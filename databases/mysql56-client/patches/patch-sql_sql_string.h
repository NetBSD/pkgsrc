$NetBSD: patch-sql_sql_string.h,v 1.1 2013/02/13 21:00:08 adam Exp $

Portability: include <bstring.h> if exists.

--- sql/sql_string.h.orig	2013-02-12 11:46:16.000000000 +0000
+++ sql/sql_string.h
@@ -22,6 +22,9 @@
 #include "my_sys.h"              /* alloc_root, my_free, my_realloc */
 #include "m_string.h"                           /* TRASH */
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
 
 /**
   A wrapper class for null-terminated constant strings.
