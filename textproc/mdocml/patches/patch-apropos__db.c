$NetBSD: patch-apropos__db.c,v 1.3 2013/12/29 19:19:03 tron Exp $

SunOS fix.

--- apropos_db.c.orig	2013-10-05 15:09:07.000000000 +0100
+++ apropos_db.c	2013-12-29 19:07:21.000000000 +0000
@@ -30,14 +30,19 @@
 #include <string.h>
 #include <unistd.h>
 
-#if defined(__linux__)
-# include <endian.h>
-# include <db_185.h>
-#elif defined(__APPLE__)
+#if defined(__APPLE__)
 # include <libkern/OSByteOrder.h>
-# include <db.h>
+#elif defined(__linux__)
+# include <endian.h>
+#elif defined(__sun)
+# include <sys/byteorder.h>
 #else
 # include <sys/endian.h>
+#endif
+
+#if defined(__linux__) || defined(__sun) 
+# include <db_185.h>
+#else
 # include <db.h>
 #endif
 
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
