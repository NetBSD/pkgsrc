$NetBSD: patch-libs_png_pngconf.h,v 1.1 2026/02/07 20:25:53 chuck Exp $

On MACOSX: Include <math.h> instead of attempting to include
deprecated <fp.h> (and getting a "fatal error: 'fp.h' file not found" err).

--- libs/png/pngconf.h.orig	2026-02-07 19:53:11.137655172 +0000
+++ libs/png/pngconf.h
@@ -297,9 +297,9 @@
 
 /* Try to determine if we are compiling on a Mac.  Note that testing for
  * just __MWERKS__ is not good enough, because the Codewarrior is now used
- * on non-Mac platforms.
+ * on non-Mac platforms.  Not necessary on MACOSX.
  */
-#ifndef MACOS
+#if !defined(MACOS) && !defined(MACOSX)
 #  if (defined(__MWERKS__) && defined(macintosh)) || defined(applec) || \
       defined(THINK_C) || defined(__SC__) || defined(TARGET_OS_MAC)
 #    define MACOS
