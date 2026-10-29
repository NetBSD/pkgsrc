$NetBSD: patch-src_base_sysinfo.cc,v 1.5 2026/10/29 05:55:20 adam Exp $

Get program pathname from sysctl on NetBSD.

--- src/base/sysinfo.cc.orig	2026-03-07 01:38:09.000000000 +0000
+++ src/base/sysinfo.cc
@@ -50,7 +50,7 @@
 #include <unistd.h>  // for read()
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -330,7 +330,7 @@ const char* GetProgramInvocationName() {
     if (_NSGetExecutablePath(program_invocation_name, &length)) return nullptr;
   }
   return program_invocation_name;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   static char program_invocation_name[PATH_MAX];
   size_t len = sizeof(program_invocation_name);
   static const int name[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
