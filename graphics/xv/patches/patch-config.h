$NetBSD: patch-config.h,v 1.2 2025/04/19 23:14:24 tsutsui Exp $

- make ghostscript support optional
- use pkgsrc ${PREFIX} for ghostscript files
- pull XRandR support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/a84406cb

--- config.h.orig	2025-04-19 21:39:43.932827163 +0000
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
@@ -282,6 +284,16 @@
 /* #  define TV_FONTSET "-*-fixed-medium-r-normal--%d-*" */
 #endif /* TV_L10N */
 
+/***************************************************************************
+ * X11 Rotate And Resize Support
+ *
+ * if you want XV to adjust the max(pect) sizes to your current screen size
+ * and you have the XRandR headers and library installed
+ */
+
+#ifdef DOXRANDR
+#  define HAVE_XRR
+#endif
 
 /***************************************************************************
  * User definable filter support:
