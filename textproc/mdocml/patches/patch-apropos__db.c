$NetBSD: patch-apropos__db.c,v 1.4 2013/12/31 11:06:30 wiz Exp $

SunOS fix.

--- apropos_db.c.orig	2013-10-05 15:09:07.000000000 +0100
+++ apropos_db.c	2013-12-29 19:07:21.000000000 +0000
@@ -141,6 +146,14 @@
 			const struct expr *, size_t terms,
 			struct mchars *, int);
 
+#ifdef __sun
+#define strsep pkgsrc_strsep
+#define strcasestr pkgsrc_strcasestr
+
+#include "strsep.c"
+#include "strcasestr.c"
+#endif
+
 /*
  * Open the keyword mandoc-db database.
  */
