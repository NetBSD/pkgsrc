$NetBSD: patch-processcore_processes__netbsd__p.cpp,v 1.1 2025/11/23 20:03:56 markd Exp $

No more sys/user.h in netbsd.

--- processcore/processes_netbsd_p.cpp.orig	2025-11-04 15:00:08.000000000 +0000
+++ processcore/processes_netbsd_p.cpp
@@ -6,6 +6,8 @@
 */
 
 #include "process.h"
+
+#include "memoryinfo_p.h"
 #include "processes_local_p.h"
 
 #include <KLocalizedString>
@@ -20,7 +22,7 @@
 #include <sys/stat.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <unistd.h>
 
 namespace KSysGuard
@@ -95,7 +97,7 @@ void ProcessesLocal::Private::readProcSt
     process->setEgid(p->p_gid);
     process->setTracerpid(-1);
 
-    process->setName(QString(p->p_comm ? p->p_comm : "????"));
+    process->setName(QString::fromUtf8(p->p_comm ? p->p_comm : "????"));
 }
 
 void ProcessesLocal::Private::readProcStat(struct kinfo_proc2 *p, Process *ps)
@@ -110,8 +112,13 @@ void ProcessesLocal::Private::readProcSt
     ps->setSysUsage(0);
 
     ps->setNiceLevel(p->p_nice - NZERO);
-    ps->setVmSize((p->p_vm_tsize + p->p_vm_dsize + p->p_vm_ssize) * getpagesize());
-    ps->setVmRSS(p->p_vm_rssize * getpagesize());
+
+    MemoryFields fields;
+    fields.rss = p->p_vm_rssize * getpagesize();
+    fields.lastUpdate = std::chrono::steady_clock::now();
+    ps->memoryInfo()->imprecise = fields;
+    ps->memoryInfo()->vmSize = (p->p_vm_tsize + p->p_vm_dsize + p->p_vm_ssize) * getpagesize();
+    ps->addChange(Process::Memory);
 
     // "idle","run","sleep","stop","zombie"
     switch (p->p_stat) {
@@ -145,11 +152,6 @@ void ProcessesLocal::Private::readProcSt
 
 void ProcessesLocal::Private::readProcStatm(struct kinfo_proc2 *p, Process *process)
 {
-    // TODO
-
-    //     unsigned long shared;
-    //     process->vmURSS = process->vmRSS - (shared * sysconf(_SC_PAGESIZE) / 1024);
-    process->setVmURSS(-1);
 }
 
 bool ProcessesLocal::Private::readProcCmdline(struct kinfo_proc2 *p, Process *process)
@@ -160,11 +162,11 @@ bool ProcessesLocal::Private::readProcCm
         return false;
     }
 
-    QString command = QString("");
+    QString command = QString::fromUtf8("");
 
     while (*argv) {
-        command += *argv;
-        command += " ";
+        command += QString::fromUtf8(*argv);
+        command += QString::fromUtf8(" ");
         argv++;
     }
     process->setCommand(command.trimmed());
