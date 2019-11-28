$NetBSD: patch-src_symbolize.cc,v 1.1 2019/11/28 12:19:58 bouyer Exp $

Get program pathname from sysctl on NetBSD

--- src/symbolize.cc.orig	2017-12-09 17:29:18.000000000 +0100
+++ src/symbolize.cc	2019-11-27 18:40:56.000000000 +0100
@@ -60,7 +60,7 @@
 #include "base/commandlineflags.h"
 #include "base/logging.h"
 #include "base/sysinfo.h"
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -97,7 +97,7 @@
       return NULL;
   }
   return program_invocation_name;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   static char program_invocation_name[PATH_MAX];
   size_t len = sizeof(program_invocation_name);
   static const int name[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
