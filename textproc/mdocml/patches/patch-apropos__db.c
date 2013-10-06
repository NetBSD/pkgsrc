$NetBSD: patch-apropos__db.c,v 1.1 2013/10/06 15:48:42 wiz Exp $

--- apropos_db.c.orig	2013-10-05 14:09:07.000000000 +0000
+++ apropos_db.c
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
+#if defined(__linux__)
+# include <db_185.h>
+#else
 # include <db.h>
 #endif
 
