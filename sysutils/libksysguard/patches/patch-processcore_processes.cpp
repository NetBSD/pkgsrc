$NetBSD: patch-processcore_processes.cpp,v 1.1 2023/10/14 03:37:59 markd Exp $

--- processcore/processes.cpp.orig	2022-07-11 10:53:39.000000000 +0000
+++ processcore/processes.cpp
@@ -156,6 +156,7 @@ bool Processes::updateProcess(Process *p
 
 bool Processes::updateProcessInfo(Process *ps)
 {
+#ifndef Q_OS_NETBSD
     // Now we can actually get the process info
     qlonglong oldUserTime = ps->userTime();
     qlonglong oldSysTime = ps->sysTime();
@@ -175,6 +176,7 @@ bool Processes::updateProcessInfo(Proces
         oldIoCharactersActuallyRead = ps->ioCharactersActuallyRead();
         oldIoCharactersActuallyWritten = ps->ioCharactersActuallyWritten();
     }
+#endif
 
     ps->setChanges(Process::Nothing);
     bool success;
@@ -208,12 +210,14 @@ bool Processes::updateProcessInfo(Proces
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
