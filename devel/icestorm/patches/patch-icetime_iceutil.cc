$NetBSD: patch-icetime_iceutil.cc,v 1.2 2024/03/02 23:07:59 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- icetime/iceutil.cc.orig	2023-12-12 12:01:19.000000000 +0000
+++ icetime/iceutil.cc	2024-03-02 22:37:27.137509507 +0000
@@ -32,7 +32,7 @@
 #  include <unistd.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/sysctl.h>
 #endif
 
@@ -51,10 +51,14 @@ std::string proc_self_dirname()
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
