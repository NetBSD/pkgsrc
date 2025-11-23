$NetBSD: patch-processcore_processes.cpp,v 1.1 2025/11/23 20:03:56 markd Exp $

--- processcore/processes.cpp.orig	2025-11-04 15:00:08.000000000 +0000
+++ processcore/processes.cpp
@@ -143,6 +143,7 @@ bool Processes::updateProcess(Process *p
 
 bool Processes::updateProcessInfo(Process *ps)
 {
+#ifndef Q_OS_NETBSD
     // Now we can actually get the process info
     qlonglong oldUserTime = ps->userTime();
     qlonglong oldSysTime = ps->sysTime();
@@ -162,6 +163,7 @@ bool Processes::updateProcessInfo(Proces
         oldIoCharactersActuallyRead = ps->ioCharactersActuallyRead();
         oldIoCharactersActuallyWritten = ps->ioCharactersActuallyWritten();
     }
+#endif
 
     ps->setChanges(Process::Nothing);
     bool success = d->mAbstractProcesses->updateProcessInfo(ps->pid(), ps);
@@ -191,12 +193,14 @@ bool Processes::updateProcessInfo(Proces
         };
 
         if (d->mUpdateFlags.testFlag(Processes::IOStatistics)) {
+#ifndef Q_OS_NETBSD
             ps->setIoCharactersReadRate(calculateRate(ps->ioCharactersRead(), oldIoCharactersRead, elapsedTime));
             ps->setIoCharactersWrittenRate(calculateRate(ps->ioCharactersWritten(), oldIoCharactersWritten, elapsedTime));
             ps->setIoReadSyscallsRate(calculateRate(ps->ioReadSyscalls(), oldIoReadSyscalls, elapsedTime));
             ps->setIoWriteSyscallsRate(calculateRate(ps->ioWriteSyscalls(), oldIoWriteSyscalls, elapsedTime));
             ps->setIoCharactersActuallyReadRate(calculateRate(ps->ioCharactersActuallyRead(), oldIoCharactersActuallyRead, elapsedTime));
             ps->setIoCharactersActuallyWrittenRate(calculateRate(ps->ioCharactersActuallyWritten(), oldIoCharactersActuallyWritten, elapsedTime));
+#endif
         } else {
             ps->setIoCharactersReadRate(0);
             ps->setIoCharactersWrittenRate(0);
