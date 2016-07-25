$NetBSD: patch-src_modules_vfs-search.c,v 1.1 2016/07/25 17:06:22 richard Exp $

SunOS needs to derive the GNU extension FNM_CASEFOLD from FNM_IGNORECASE
instead of vice versa as in *BSD.

--- src/modules/vfs-search.c.orig	2016-02-20 22:09:54.000000000 +0000
+++ src/modules/vfs-search.c
@@ -37,6 +37,9 @@
 
 #define _GNU_SOURCE /* for FNM_CASEFOLD in fnmatch.h, a GNU extension */
 #include <fnmatch.h>
+#ifndef FNM_CASEFOLD
+#define FNM_CASEFOLD FNM_IGNORECASE
+#endif
 
 #if __GNUC__ >= 4
 #pragma GCC diagnostic ignored "-Wcomment" /* for comments below */
