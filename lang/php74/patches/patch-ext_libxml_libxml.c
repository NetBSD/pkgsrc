$NetBSD: patch-ext_libxml_libxml.c,v 1.1 2025/04/22 10:17:08 wiz Exp $

Fix compatibility with libxml2 2.14.

--- ext/libxml/libxml.c.orig	2025-04-22 10:15:00.907292717 +0000
+++ ext/libxml/libxml.c
@@ -476,7 +476,7 @@ php_libxml_input_buffer_create_filename(
 static xmlOutputBufferPtr
 php_libxml_output_buffer_create_filename(const char *URI,
                               xmlCharEncodingHandlerPtr encoder,
-                              int compression ATTRIBUTE_UNUSED)
+                              int compression)
 {
 	xmlOutputBufferPtr ret;
 	xmlURIPtr puri;
