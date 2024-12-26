$NetBSD: patch-src_symbolize.cc,v 1.2 2024/12/26 17:17:42 adam Exp $

Get program pathname from sysctl on NetBSD

--- src/symbolize.cc.orig	2024-09-23 18:10:35.000000000 +0000
+++ src/symbolize.cc
@@ -61,7 +61,7 @@
 #include "base/logging.h"
 #include "base/sysinfo.h"
 #include "base/proc_maps_iterator.h"
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -141,7 +141,7 @@ static const char* GetProgramInvocationN
       return NULL;
   }
   return program_invocation_name;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   static char program_invocation_name[PATH_MAX];
   size_t len = sizeof(program_invocation_name);
   static const int name[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
