$NetBSD: patch-mandocdb.c,v 1.5 2013/10/11 14:45:18 wiz Exp $

SunOS fix.

--- mandocdb.c.orig	2013-10-05 14:09:07.000000000 +0000
+++ mandocdb.c
@@ -34,19 +34,21 @@
 #include <string.h>
 #include <unistd.h>
 
-#if defined(__linux__) || defined(__sun)
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
+# include <sys/stat.h>
 #else
 # include <sys/endian.h>
-# include <db.h>
 #endif
 
-#if defined(__sun)
-#include <sys/stat.h>
+#if defined(__linux__) || defined(__sun) 
+# include <db_185.h>
+#else
+# include <db.h>
 #endif
 
 #include "man.h"
