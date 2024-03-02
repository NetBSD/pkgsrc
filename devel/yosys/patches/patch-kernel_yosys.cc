$NetBSD: patch-kernel_yosys.cc,v 1.2 2024/03/02 23:08:00 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- kernel/yosys.cc.orig	2024-02-09 07:16:24.000000000 +0000
+++ kernel/yosys.cc	2024-03-02 22:13:47.305319491 +0000
@@ -55,7 +55,7 @@
 #  include <glob.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/sysctl.h>
 #endif
 
@@ -917,10 +917,14 @@ std::string proc_self_dirname()
 		buflen--;
 	return std::string(path, buflen);
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
+#ifdef __NetBSD__
+	int mib[4] = {CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_PATHNAME};
+#else
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+#endif
 	size_t buflen;
 	char *buffer;
 	std::string path;
