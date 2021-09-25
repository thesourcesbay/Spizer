#pragma once
#include <ntdef.h>
#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <ntstrsafe.h>
#include <wdm.h>
#pragma comment(lib, "ntoskrnl.lib")

typedef enum _SYSTEM_INFORMATION_CLASS
{

	SystemBasicInformation,
	SystemProcessorInformation,
	SystemPerfmormanceInformation,
	SystemTimeOfDayInformation,
	SystemPathInformation,
	SystemProcessInformation,
	SystemCallCountInformation,
	SystemDeviceInformation,
	SystemProcessorPerformanceInformation,
	SystemFlagsInformation,
	SystemCallTimeInformation,
	SystemModuleInformation = 0x0B

} SYSTEM_INFORMATION_CLASS,
* PSYSTEM_INFORMATION_CLASS;

typedef struct _RTL_PROCESS_MODULE_INFORMATION
{
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoaderOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];

} RTL_PROCESS_MODULE_INFORMATION, * PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES
{
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION Modules[1];

} RTL_PROCESS_MODULES, * PRTL_PROCESS_MODULES;

extern "C" _declspec(dllimport)
NTSTATUS NTAPI ZwProtectVitualMemory(

	HANDLE ProcessHandle,
	PVOID * BaseAddress,
	PULONG ProtectSize,
	ULONG NewProtect,
	PULONG OldProtect

	);

extern "C" NTKERNELAPI
PVOID
NTAPI
RtlFindExportRoutineByName(
	_In_ PVOID ImageBase,
	_In_ PCCH RountineNam

);

extern "C" NTSTATUS ZwQuerySystemInformation(ULONG InfoClass, PVOID Buffer, ULONG Length, PULONG ReturnLenght
);

extern "C" NTKERNELAPI
PPEB
PsGetProcessPeb(
	IN PEPROCESS Process

);

extern "C" NTSTATUS NTAPI MmCopyVirtualMemory
(
	PEPROCESS SourceProcess,
	PVOID SourceAddress,
	PEPROCESS TargetProcess,
	SIZE_T BufferSize,
	KPROCESSOR_MODE PreviousMode,
	PSIZE_T ReturnSize
);