$NetBSD: patch-smsd_services_pgsql.c,v 1.2 2026/08/21 11:52:39 adam Exp $

_XOPEN_SOURCE is problematic.

--- smsd/services/pgsql.c.orig	2026-08-19 10:48:50.000000000 +0000
+++ smsd/services/pgsql.c
@@ -1,7 +1,6 @@
 /* (c) 2006 by Andrea Riciputi */
 /* Copyright (c) 2009 - 2018 Michal Cihar <michal@cihar.com> */
 
-#define _XOPEN_SOURCE
 #define _BSD_SOURCE
 #define _DEFAULT_SOURCE
 #include <time.h>
