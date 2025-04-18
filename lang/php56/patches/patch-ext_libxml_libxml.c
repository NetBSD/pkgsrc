$NetBSD: patch-ext_libxml_libxml.c,v 1.1 2025/04/18 15:54:30 wiz Exp $

Symbol was removed in libxml2 2.14.

--- ext/libxml/libxml.c.orig	2025-04-18 15:51:46.828853724 +0000
+++ ext/libxml/libxml.c
@@ -421,7 +421,7 @@ php_libxml_input_buffer_create_filename(
 static xmlOutputBufferPtr
 php_libxml_output_buffer_create_filename(const char *URI,
                               xmlCharEncodingHandlerPtr encoder,
-                              int compression ATTRIBUTE_UNUSED)
+                              int compression)
 {
 	xmlOutputBufferPtr ret;
 	xmlURIPtr puri;
