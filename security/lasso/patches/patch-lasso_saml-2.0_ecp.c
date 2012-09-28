$NetBSD: patch-lasso_saml-2.0_ecp.c,v 1.1 2012/09/28 11:59:18 obache Exp $

* for libxml2>=2.9.0

--- lasso/saml-2.0/ecp.c.orig	2011-01-05 13:57:32.000000000 +0000
+++ lasso/saml-2.0/ecp.c
@@ -175,7 +175,7 @@ lasso_ecp_process_authn_request_msg(Lass
 	xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 0, "utf-8");
 	xmlOutputBufferFlush(buf);
 	LASSO_PROFILE(ecp)->msg_body = g_strdup(
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
+			(char*)(xmlBufferContent(buf->conv ? buf->conv : buf->buffer)));
 	xmlOutputBufferClose(buf);
 	lasso_release_doc(doc);
 
@@ -276,7 +276,7 @@ lasso_ecp_process_response_msg(LassoEcp 
 	xmlNodeDumpOutput(buf, NULL, new_envelope, 0, 0, "utf-8");
 	xmlOutputBufferFlush(buf);
 	LASSO_PROFILE(ecp)->msg_body = g_strdup(
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
+			(char*)(xmlBufferContent(buf->conv ? buf->conv : buf->buffer)));
 	xmlOutputBufferClose(buf);
 
 	lasso_release_doc(doc);
