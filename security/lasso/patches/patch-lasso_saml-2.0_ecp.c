$NetBSD: patch-lasso_saml-2.0_ecp.c,v 1.2 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/lasso/saml-2.0/ecp.c b/lasso/saml-2.0/ecp.c
index 655162c..9ef9d97 100644
--- lasso/saml-2.0/ecp.c
+++ lasso/saml-2.0/ecp.c
@@ -128,8 +128,6 @@ lasso_ecp_process_authn_request_msg(LassoEcp *ecp, const char *authn_request_msg
 	xmlXPathContext *xpathCtx;
 	xmlXPathObject *xpathObj;
 	xmlNode *xmlnode;
-	xmlOutputBuffer *buf;
-	xmlCharEncodingHandler *handler;
 	LassoProfile *profile;
 	LassoProvider *remote_provider;
 
@@ -170,13 +168,8 @@ lasso_ecp_process_authn_request_msg(LassoEcp *ecp, const char *authn_request_msg
 	xpathObj = NULL;
 
 	xmlnode = xmlDocGetRootElement(doc);
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	LASSO_PROFILE(ecp)->msg_body = g_strdup(
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
-	xmlOutputBufferClose(buf);
+	lasso_assign_new_string(LASSO_PROFILE(ecp)->msg_body,
+			lasso_xmlnode_to_string(xmlnode, 0, 0))
 	lasso_release_doc(doc);
 
 	profile->remote_providerID = lasso_server_get_first_providerID_by_role(profile->server, LASSO_PROVIDER_ROLE_IDP);
@@ -206,8 +199,6 @@ lasso_ecp_process_response_msg(LassoEcp *ecp, const char *response_msg)
 	xmlXPathObject *xpathObj;
 	xmlNode *new_envelope, *header, *paos_response, *ecp_relay_state;
 	xmlNode *body = NULL;
-	xmlOutputBuffer *buf;
-	xmlCharEncodingHandler *handler;
 	xmlNs *soap_env_ns, *ecp_ns;
 
 	g_return_val_if_fail(LASSO_IS_ECP(ecp), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
@@ -270,17 +261,9 @@ lasso_ecp_process_response_msg(LassoEcp *ecp, const char *response_msg)
 	}
 
 	xmlAddChild(new_envelope, body);
-
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, new_envelope, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	LASSO_PROFILE(ecp)->msg_body = g_strdup(
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
-	xmlOutputBufferClose(buf);
-
+	lasso_assign_new_string(LASSO_PROFILE(ecp)->msg_body,
+			lasso_xmlnode_to_string(new_envelope, 0, 0))
 	lasso_release_doc(doc);
-
 	return 0;
 }
 
