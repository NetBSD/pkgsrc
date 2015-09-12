$NetBSD: patch-src_platform.h,v 1.1 2015/09/12 18:51:07 wiz Exp $

======================================================
This patch adds NetBSD as a known platform.

It has been submitted upstream.
https://github.com/matricks/bam/pull/84/  (2nd commit)
======================================================


--- src/platform.h.orig	2010-08-09 20:08:24.000000000 +0200
+++ src/platform.h	2015-09-12 03:51:29.000000000 +0200
@@ -34,6 +34,13 @@
 	#define BAM_PLATFORM_STRING "openbsd"
 #endif
 
+#if defined(__NetBSD__)
+	#define BAM_FAMILY_UNIX
+	#define BAM_FAMILY_STRING "unix"
+	#define BAM_PLATFORM_NETBSD
+	#define BAM_PLATFORM_STRING "netbsd"
+#endif
+
 #if defined(__LINUX__) || defined(__linux__)
 	#define BAM_FAMILY_UNIX
 	#define BAM_FAMILY_STRING "unix"
