$NetBSD: patch-sql_sql_string.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Portability: include <bstring.h> if exists.

--- sql/sql_string.h.orig	2015-02-13 12:07:04.000000000 +0000
+++ sql/sql_string.h
@@ -20,6 +20,10 @@
 
 /* This file is originally from the mysql distribution. Coded by monty */
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #ifdef USE_PRAGMA_INTERFACE
 #pragma interface			/* gcc class implementation */
 #endif
