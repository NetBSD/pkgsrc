$NetBSD: patch-base_gdevpng.c,v 1.1 2013/03/16 21:32:01 dholland Exp $

The patch was included in patches/patch-ak:
  revision 1.5
  date: 2011/01/15 14:08:10;  author: wiz;  state: Exp;  lines: +194 -29
  Fix build with png-1.5. Patch from John Bowler in private mail.

  and 'fix for build with png-1.5' is now included in upstream in different
  shape, so some left out is here:

--- base/gdevpng.c.orig	2011-08-05 20:12:20.000000000 +0900
+++ base/gdevpng.c	2011-08-22 19:04:12.000000000 +0900
@@ -40,8 +40,11 @@
 /*
  * libpng versions 1.0.3 and later allow disabling access to the stdxxx
  * files while retaining support for FILE * I/O.
+ *
+ * This is a misunderstanding - this is a build time option for libpng,
+ * it has no effect on a user of libpng.
  */
-#define PNG_NO_CONSOLE_IO
+/*#define PNG_NO_CONSOLE_IO*/
 /*
  * Earlier libpng versions require disabling FILE * I/O altogether.
  * This produces a compiler warning about no prototype for png_init_io.
