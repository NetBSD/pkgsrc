$NetBSD: patch-icetime_iceutil.cc,v 1.1 2024/02/28 06:02:39 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- icetime/iceutil.cc.orig	2024-02-27 14:44:02.760248201 +0000
+++ icetime/iceutil.cc	2024-02-27 14:45:11.872738091 +0000
@@ -32,7 +32,7 @@
 #  include <unistd.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/sysctl.h>
 #endif
 
@@ -51,7 +51,7 @@ std::string proc_self_dirname()
 		buflen--;
 	return std::string(path, buflen);
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
