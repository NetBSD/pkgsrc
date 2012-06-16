$NetBSD: patch-lib_php_src_ext_thrift__protocol_php__thrift__protocol.cpp,v 1.1 2012/06/16 01:42:58 taca Exp $

Use modern data structure name.

--- lib/php/src/ext/thrift_protocol/php_thrift_protocol.cpp.orig	2011-08-11 13:19:15.000000000 +0000
+++ lib/php/src/ext/thrift_protocol/php_thrift_protocol.cpp
@@ -92,7 +92,7 @@ const int BAD_VERSION = 4;
 #include "zend_exceptions.h"
 #include "php_thrift_protocol.h"
 
-static function_entry thrift_protocol_functions[] = {
+static zend_function_entry thrift_protocol_functions[] = {
   PHP_FE(thrift_protocol_write_binary, NULL)
   PHP_FE(thrift_protocol_read_binary, NULL)
   {NULL, NULL, NULL}
