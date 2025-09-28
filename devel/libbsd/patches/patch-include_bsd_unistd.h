$NetBSD: patch-include_bsd_unistd.h,v 1.1 2025/09/28 06:18:35 vins Exp $

Avoid type clash for closefrom() on NetBSD.

--- include/bsd/unistd.h.orig	2024-02-11 18:30:03.000000000 +0000
+++ include/bsd/unistd.h
@@ -61,9 +61,10 @@ int bsd_getopt(int argc, char * const ar
 mode_t getmode(const void *set, mode_t mode);
 void *setmode(const char *mode_str);
 
-#if !defined(__GLIBC__) || \
+#if !defined(__NetBSD__) && (\
+    !defined(__GLIBC__) || \
     !__GLIBC_PREREQ(2, 34) || \
-    !defined(_DEFAULT_SOURCE)
+    !defined(_DEFAULT_SOURCE))
 void closefrom(int lowfd);
 #endif
 
