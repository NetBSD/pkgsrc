$NetBSD: patch-smsd_services_sql.c,v 1.1 2018/07/31 13:13:46 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- smsd/services/sql.c.orig	2018-01-05 10:14:14.000000000 +0000
+++ smsd/services/sql.c
@@ -9,7 +9,9 @@
  * Licensed under GNU GPL version 2 or later
  */
 
+#if !defined(__sun)
 #define _XOPEN_SOURCE
+#endif
 #define _BSD_SOURCE
 #define _DEFAULT_SOURCE
 #include <time.h>
