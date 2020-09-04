$NetBSD: patch-ncurses_tinfo_lib_raw.c,v 1.1 2020/09/04 10:33:14 js Exp $

--- ncurses/tinfo/lib_raw.c.orig	2020-02-02 23:34:34.000000000 +0000
+++ ncurses/tinfo/lib_raw.c
@@ -54,3 +54,3 @@ MODULE_ID("$Id: lib_raw.c,v 1.24 2020/02
 
-#if HAVE_SYS_TERMIO_H
+#if HAVE_SYS_TERMIO_H && !defined(__QNX__)
 #include <sys/termio.h>		/* needed for ISC */
