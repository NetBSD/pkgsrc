$NetBSD: patch-plugins_freedns.c,v 1.3 2019/12/13 21:52:04 dmcmahill Exp $

If the update call fails, log the response from the remote service

--- plugins/freedns.c.orig	2018-08-29 17:40:11.000000000 -0500
+++ plugins/freedns.c
@@ -59,5 +59,5 @@
 	http_t        client;
 	http_trans_t  trans;
-	char         *buf, *tmp, *line, *hash = NULL;
+	char         *buf, *tmp, *line, *hash = NULL, *errmsg = NULL;
 	char          host[256], updateurl[256];
 	char          buffer[256];
@@ -110,7 +110,8 @@
 		free(buf);
 
-		if (!hash)
+		if (!hash) {
+                        errmsg = trans.rsp_body;
 			rc = RC_DDNS_RSP_NOTOK;
-		else
+		} else
 			hash++;
 	}
@@ -118,7 +119,11 @@
 
 	if (rc) {
-		if (rc == RC_DDNS_RSP_NOTOK)
-			logit(LOG_INFO, "Cannot find your DNS name in the list of API keys");
-		else
+		if (rc == RC_DDNS_RSP_NOTOK) {
+			if (errmsg != NULL) {
+				logit(LOG_INFO, "Cannot find your DNS name in the list of API keys (%s)", errmsg);
+			} else {
+				logit(LOG_INFO, "Cannot find your DNS name in the list of API keys");
+			}
+		} else
 			logit(LOG_INFO, "Cannot find you FreeDNS account API keys");
 
