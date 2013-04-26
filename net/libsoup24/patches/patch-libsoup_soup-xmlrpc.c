$NetBSD: patch-libsoup_soup-xmlrpc.c,v 1.1 2013/04/26 19:54:14 joerg Exp $

--- libsoup/soup-xmlrpc.c.orig	2013-04-26 18:46:35.000000000 +0000
+++ libsoup/soup-xmlrpc.c
@@ -289,7 +289,7 @@ soup_xmlrpc_build_method_response (GValu
 	return body;
 }
 
-static char *
+static G_GNUC_PRINTF (2, 0) char *
 soup_xmlrpc_build_faultv (int fault_code, const char *fault_format, va_list args)
 {
 	xmlDoc *doc;
