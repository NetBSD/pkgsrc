$NetBSD: patch-lasso_id-ff_lecp.c,v 1.1 2012/09/28 11:59:18 obache Exp $

* for libxml2>=2.9.0

--- lasso/id-ff/lecp.c.orig	2011-01-05 13:57:32.000000000 +0000
+++ lasso/id-ff/lecp.c
@@ -96,7 +96,7 @@ lasso_lecp_build_authn_request_envelope_
 	xmlOutputBufferFlush(buf);
 
 	lasso_assign_string(profile->msg_body,
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
+			(char*)(xmlBufferContent(buf->conv ? buf->conv : buf->buffer)));
 	xmlOutputBufferClose(buf);
 	xmlFreeNode(msg);
 
@@ -342,7 +342,7 @@ lasso_lecp_process_authn_request_envelop
 	xmlNodeDumpOutput(buf, NULL, soap_envelope, 0, 0, "utf-8");
 	xmlOutputBufferFlush(buf);
 	LASSO_PROFILE(lecp)->msg_body = g_strdup( (char*)(
-			buf->conv ? buf->conv->content : buf->buffer->content));
+			buf->conv ? xmlBufferContent(buf->conv) : xmlBufferContent(buf->buffer)));
 	xmlOutputBufferClose(buf);
 	xmlFreeNode(soap_envelope);
 
