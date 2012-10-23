$NetBSD: patch-lasso_id-ff_lecp.c,v 1.2 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/lasso/id-ff/lecp.c b/lasso/id-ff/lecp.c
index 6ca9515..1dd53b6 100644
--- lasso/id-ff/lecp.c
+++ lasso/id-ff/lecp.c
@@ -58,8 +58,6 @@ lasso_lecp_build_authn_request_envelope_msg(LassoLecp *lecp)
 	LassoProfile *profile;
 	gchar *assertionConsumerServiceURL;
 	xmlNode *msg;
-	xmlOutputBuffer *buf;
-	xmlCharEncodingHandler *handler;
 
 	g_return_val_if_fail(LASSO_IS_LECP(lecp), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
 
@@ -89,16 +87,7 @@ lasso_lecp_build_authn_request_envelope_msg(LassoLecp *lecp)
 		LASSO_PROFILE(lecp)->server->certificate;
 	msg = lasso_node_get_xmlNode(LASSO_NODE(lecp->authnRequestEnvelope), FALSE);
 
-	/* msg is not SOAP but straight XML */
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, msg, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-
-	lasso_assign_string(profile->msg_body,
-			(char*)(buf->conv ? buf->conv->content : buf->buffer->content));
-	xmlOutputBufferClose(buf);
-	xmlFreeNode(msg);
+	lasso_assign_new_string(profile->msg_body, lasso_xmlnode_to_string(msg, 0, 0))
 
 	if (profile->msg_body == NULL) {
 		return LASSO_PROFILE_ERROR_BUILDING_REQUEST_FAILED;
@@ -299,8 +288,6 @@ lasso_lecp_process_authn_request_envelope_msg(LassoLecp *lecp, const char *reque
 	xmlXPathContext *xpathCtx;
 	xmlXPathObject *xpathObj;
 	xmlNode *soap_envelope, *soap_body, *authn_request;
-	xmlOutputBuffer *buf;
-	xmlCharEncodingHandler *handler;
 
 	g_return_val_if_fail(LASSO_IS_LECP(lecp), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
 	g_return_val_if_fail(request_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);
@@ -337,13 +324,8 @@ lasso_lecp_process_authn_request_envelope_msg(LassoLecp *lecp, const char *reque
 	soap_body = xmlNewTextChild(soap_envelope, NULL, (xmlChar*)"Body", NULL);
 	xmlAddChild(soap_body, authn_request);
 
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, soap_envelope, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	LASSO_PROFILE(lecp)->msg_body = g_strdup( (char*)(
-			buf->conv ? buf->conv->content : buf->buffer->content));
-	xmlOutputBufferClose(buf);
+	lasso_assign_new_string(LASSO_PROFILE(lecp)->msg_body,
+			lasso_xmlnode_to_string(soap_envelope, 0, 0));
 	xmlFreeNode(soap_envelope);
 
 
