$NetBSD: patch-sql_sql_string.h,v 1.1 2013/02/12 20:36:29 adam Exp $

Portability: include <bstring.h> if exists.

--- sql/sql_string.h.orig	2013-02-12 11:35:13.000000000 +0000
+++ sql/sql_string.h
@@ -18,6 +18,10 @@
 
 /* This file is originally from the mysql distribution. Coded by monty */
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #ifdef USE_PRAGMA_INTERFACE
 #pragma interface			/* gcc class implementation */
 #endif
