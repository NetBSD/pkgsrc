$NetBSD: patch-storage_innobase_handler_i__s.cc,v 1.1 2020/07/07 20:18:20 adam Exp $

Add missing include.

--- storage/innobase/handler/i_s.cc.orig	2020-07-07 19:03:24.000000000 +0000
+++ storage/innobase/handler/i_s.cc
@@ -31,6 +31,7 @@ InnoDB INFORMATION SCHEMA tables interfa
 Created July 18, 2007 Vasil Dimov
 *******************************************************/
 
+#include <string>
 #include <mysqld_error.h>
 #include <sql_acl.h>
 
