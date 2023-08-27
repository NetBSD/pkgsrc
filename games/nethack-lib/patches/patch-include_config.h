$NetBSD: patch-include_config.h,v 1.2 2023/08/27 15:59:19 rhialto Exp $

Make window system configurable.

--- include/config.h.orig	2023-02-15 21:52:57.000000000 +0000
+++ include/config.h
@@ -42,6 +42,19 @@
  * Define all of those you want supported in your binary.
  * Some combinations make no sense.  See the installation document.
  */
+#if   defined(GTYPE_TTY)
+#  define DEFAULT_WINDOW_SYS "tty"
+#elif   defined(GTYPE_CURSES)
+#  define CURSES_GRAPHICS
+#  define DEFAULT_WINDOW_SYS "curses"
+#elif defined(GTYPE_X11)
+#  define X11_GRAPHICS
+#  define DEFAULT_WINDOW_SYS "X11"
+#elif defined(GTYPE_QT)
+#  define QT_GRAPHICS
+#  define DEFAULT_WINDOW_SYS "Qt"
+#endif
+
 #if !defined(NOTTYGRAPHICS)
 #define TTY_GRAPHICS /* good old tty based graphics */
 #endif
@@ -134,7 +147,7 @@
  * would allow:
  *  xpmtoppm <x11tiles.xpm | pnmscale 1.25 | ppmquant 90 >x11tiles_big.xpm
  */
-/* # define USE_XPM */ /* Disable if you do not have the XPM library */
+#define USE_XPM /* Disable if you do not have the XPM library */
 #ifdef USE_XPM
 #define GRAPHIC_TOMBSTONE /* Use graphical tombstone (rip.xpm) */
 #endif
@@ -263,11 +276,8 @@
 
 #if defined(UNIX) && !defined(ZLIB_COMP) && !defined(COMPRESS)
 /* path and file name extension for compression program */
-#define COMPRESS "/usr/bin/compress" /* Lempel-Ziv compression */
-#define COMPRESS_EXTENSION ".Z"      /* compress's extension */
-/* An example of one alternative you might want to use: */
-/* #define COMPRESS "/usr/local/bin/gzip" */ /* FSF gzip compression */
-/* #define COMPRESS_EXTENSION ".gz" */       /* normal gzip extension */
+#define COMPRESS "@GZIP_PROGRAM@"      /* FSF gzip compression */
+#define COMPRESS_EXTENSION ".gz"       /* normal gzip extension */
 #endif
 
 #ifndef COMPRESS
@@ -352,7 +362,7 @@
  * otherwise it will be the current directory.
  */
 #ifndef HACKDIR
-#define HACKDIR "/usr/games/lib/nethackdir"
+#define HACKDIR "@HACKDIR@"
 #endif
 
 /*
@@ -442,7 +452,7 @@ typedef unsigned char uchar;
  * functions that have been macroized.
  */
 
-/* #define VISION_TABLES */ /* use vision tables generated at compile time */
+#define VISION_TABLES /* use vision tables generated at compile time */
 #ifndef VISION_TABLES
 #ifndef NO_MACRO_CPATH
 #define MACRO_CPATH /* use clear_path macros instead of functions */
