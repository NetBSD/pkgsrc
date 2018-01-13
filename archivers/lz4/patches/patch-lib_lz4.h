$NetBSD: patch-lib_lz4.h,v 1.1 2018/01/13 19:00:09 adam Exp $

Set correct version number.

--- lib/lz4.h.orig	2018-01-13 18:37:33.000000000 +0000
+++ lib/lz4.h
@@ -93,7 +93,7 @@ extern "C" {
 /*------   Version   ------*/
 #define LZ4_VERSION_MAJOR    1    /* for breaking interface changes  */
 #define LZ4_VERSION_MINOR    8    /* for new (non-breaking) interface capabilities */
-#define LZ4_VERSION_RELEASE  0    /* for tweaks, bug-fixes, or development */
+#define LZ4_VERSION_RELEASE  1    /* for tweaks, bug-fixes, or development */
 
 #define LZ4_VERSION_NUMBER (LZ4_VERSION_MAJOR *100*100 + LZ4_VERSION_MINOR *100 + LZ4_VERSION_RELEASE)
 
