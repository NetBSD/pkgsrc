$NetBSD: patch-ncurses_tinfo_lib_raw.c,v 1.3 2024/03/31 14:13:17 js Exp $

QNX's <sys/termio.h> complains if some of the defines from ncurses exist.

--- ncurses/tinfo/lib_raw.c.orig	2024-03-31 14:08:41.262178407 +0000
+++ ncurses/tinfo/lib_raw.c
@@ -54,3 +54,3 @@ MODULE_ID("$Id: lib_raw.c,v 1.26 2020/11
 
-#if HAVE_SYS_TERMIO_H
+#if HAVE_SYS_TERMIO_H && !defined(__QNX__)
 #include <sys/termio.h>		/* needed for ISC */
