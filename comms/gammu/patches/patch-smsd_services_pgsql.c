$NetBSD: patch-smsd_services_pgsql.c,v 1.1 2018/07/31 13:13:46 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- smsd/services/pgsql.c.orig	2018-01-05 10:14:14.000000000 +0000
+++ smsd/services/pgsql.c
@@ -1,7 +1,9 @@
 /* (c) 2006 by Andrea Riciputi */
 /* Copyright (c) 2009 - 2018 Michal Cihar <michal@cihar.com> */
 
+#if !defined(__sun)
 #define _XOPEN_SOURCE
+#endif
 #define _BSD_SOURCE
 #define _DEFAULT_SOURCE
 #include <time.h>
