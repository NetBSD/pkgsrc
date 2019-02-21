$NetBSD: patch-config.h,v 1.1 2019/02/21 14:32:32 tsutsui Exp $

- make ghostscript support optional
- use pkgsrc ${PREFIX} for ghostscript files

--- config.h.orig	2019-02-21 14:07:37.592173395 +0000
+++ config.h
@@ -112,10 +112,12 @@
  * should not need to be changed
  */
 
+#ifdef DOGS
 /* #define GS_PATH "/usr/local/bin/gs" */
-#define GS_PATH "gs"
-/* #define GS_LIB  "."                 */
-/* #define GS_DEV  "ppmraw"            */
+#define GS_PATH "@PREFIX@/bin/gs"
+#define GS_LIB "@PREFIX@/share/ghostscript"
+#define GS_DEV "ppmraw"
+#endif
 
 
 /***************************************************************************
