$NetBSD: patch-client_sql_string.h,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

Portability: include <bstring.h> if exists.

--- client/sql_string.h.orig	2013-02-12 11:01:12.000000000 +0000
+++ client/sql_string.h
@@ -21,6 +21,10 @@
 #include "m_ctype.h"
 #include "my_sys.h"
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 class String;
 int sortcmp(const String *a,const String *b, const CHARSET_INFO *cs);
 String *copy_if_not_alloced(String *a,String *b,uint32 arg_length);
