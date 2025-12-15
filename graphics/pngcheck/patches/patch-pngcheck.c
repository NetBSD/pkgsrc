$NetBSD: patch-pngcheck.c,v 1.1 2025/12/15 21:06:01 wiz Exp $

Fix build on NetBSD.
https://github.com/pnggroup/pngcheck/pull/63

--- pngcheck.c.orig	2025-12-15 21:02:58.149679413 +0000
+++ pngcheck.c
@@ -126,7 +126,7 @@
 #  endif
 #endif
 
-#if defined(unix) || (defined(__MWERKS__) && defined(macintosh))  /* pxm */
+#if defined(unix) || defined(__NetBSD__) || (defined(__MWERKS__) && defined(macintosh))  /* pxm */
 #  include <unistd.h>	/* isatty() */
 #endif
 #if defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
