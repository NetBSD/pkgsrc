$NetBSD: patch-src_main.c,v 1.1 2018/01/31 10:22:48 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/main.c.orig	2017-02-19 04:39:08.000000000 +0000
+++ src/main.c
@@ -2,7 +2,9 @@
    This file is part of Potrace. It is free software and it is covered
    by the GNU General Public License. See the file COPYING for details. */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
