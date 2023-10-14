$NetBSD: patch-processcore_processes__netbsd__p.cpp,v 1.1 2023/10/14 03:37:59 markd Exp $

No more sys/user.h in netbsd.

--- processcore/processes_netbsd_p.cpp.orig	2022-07-11 10:53:39.000000000 +0000
+++ processcore/processes_netbsd_p.cpp
@@ -20,7 +20,7 @@
 #include <sys/stat.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <unistd.h>
 
 namespace KSysGuard
@@ -92,7 +92,7 @@ void ProcessesLocal::Private::readProcSt
     process->setEgid(p->p_gid);
     process->setTracerpid(-1);
 
-    process->setName(QString(p->p_comm ? p->p_comm : "????"));
+    process->setName(QString::fromUtf8(p->p_comm ? p->p_comm : "????"));
 }
 
 void ProcessesLocal::Private::readProcStat(struct kinfo_proc2 *p, Process *ps)
@@ -156,11 +156,11 @@ bool ProcessesLocal::Private::readProcCm
     if ((argv = kvm_getargv2(kd, p, 256)) == NULL)
         return false;
 
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
