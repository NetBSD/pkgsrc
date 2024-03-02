$NetBSD: patch-kernel_yosys.cc,v 1.1 2024/03/02 02:03:37 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- kernel/yosys.cc.orig	2024-02-29 13:30:05.586482076 +0000
+++ kernel/yosys.cc	2024-02-29 13:30:54.466426964 +0000
@@ -55,7 +55,7 @@
 #  include <glob.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/sysctl.h>
 #endif
 
@@ -917,7 +917,7 @@ std::string proc_self_dirname()
 		buflen--;
 	return std::string(path, buflen);
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
