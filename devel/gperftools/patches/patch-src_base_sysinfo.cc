$NetBSD: patch-src_base_sysinfo.cc,v 1.4 2025/11/11 09:52:27 adam Exp $

Get program pathname from sysctl on NetBSD.

--- src/base/sysinfo.cc.orig	2025-08-05 07:55:48.450335710 +0000
+++ src/base/sysinfo.cc
@@ -49,7 +49,7 @@
 #include <unistd.h>   // for read()
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -437,7 +437,7 @@ const char* GetProgramInvocationName() {
       return nullptr;
   }
   return program_invocation_name;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   static char program_invocation_name[PATH_MAX];
   size_t len = sizeof(program_invocation_name);
   static const int name[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
