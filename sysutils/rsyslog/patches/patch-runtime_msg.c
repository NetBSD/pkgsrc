$NetBSD: patch-runtime_msg.c,v 1.1 2014/09/05 07:15:41 fhajny Exp $

Fix build with newer json-c.
--- runtime/msg.c.orig	2014-08-18 09:14:06.000000000 +0000
+++ runtime/msg.c
@@ -4074,7 +4074,11 @@ MsgSetPropsViaJSON(msg_t *__restrict__ c
 
 			err = tokener->err;
 			if(err != json_tokener_continue)
-				errMsg = json_tokener_errors[err];
+#if				HAVE_JSON_TOKENER_ERROR_DESC
+					errMsg = json_tokener_error_desc(err);
+#				else
+					errMsg = json_tokener_errors[err];
+#				endif
 			else
 				errMsg = "Unterminated input";
 		} else if(!json_object_is_type(json, json_type_object))
