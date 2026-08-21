$NetBSD: patch-smsd_services_sql.c,v 1.2 2026/08/21 11:52:40 adam Exp $

_XOPEN_SOURCE is problematic.

--- smsd/services/sql.c.orig	2026-08-19 10:48:50.000000000 +0000
+++ smsd/services/sql.c
@@ -9,7 +9,6 @@
  * Licensed under GNU GPL version 2 or later
  */
 
-#define _XOPEN_SOURCE
 #define _BSD_SOURCE
 #define _DEFAULT_SOURCE
 #include <time.h>
