$NetBSD: patch-common_kernel_command.cc,v 1.1 2024/02/28 06:31:58 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- common/kernel/command.cc.orig	2024-02-28 04:07:47.135026596 +0000
+++ common/kernel/command.cc	2024-02-28 04:08:20.420487475 +0000
@@ -61,7 +61,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -90,7 +90,7 @@ std::string proc_self_dirname()
         buflen--;
     return std::string(path, buflen);
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
     int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
