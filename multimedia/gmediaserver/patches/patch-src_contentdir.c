$NetBSD: patch-src_contentdir.c,v 1.1 2012/04/13 23:52:11 obache Exp $

* assert.h for assert(3)

--- src/contentdir.c.orig	2007-10-20 07:59:38.000000000 +0000
+++ src/contentdir.c
@@ -22,6 +22,7 @@
 #include <stdint.h>		/* Gnulib/C99 */
 #include <inttypes.h>		/* ? */
 #include <sys/stat.h>		/* POSIX */
+#include <assert.h>
 #include "gettext.h"		/* Gnulib/gettext */
 #define _(s) gettext(s)
 #define N_(s) gettext_noop(s)
