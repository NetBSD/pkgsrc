$NetBSD: patch-plugins_freedns.c,v 1.2 2016/05/29 22:32:12 abs Exp $

If the update call fails, log the response from the remote service

--- plugins/freedns.c.orig	2015-09-09 19:27:51.000000000 +0000
+++ plugins/freedns.c
@@ -55,7 +55,7 @@ static int request(ddns_t *ctx, ddns_inf
 	int           i, rc = 0;
 	http_t        client;
 	http_trans_t  trans;
-	char         *buf, *tmp, *line, *hash = NULL;
+	char         *buf, *tmp, *line, *hash = NULL, *errmsg = NULL;
 	char          host[256], updateurl[256];
 	char          buffer[256];
 	char          digeststr[SHA1_DIGEST_BYTES * 2 + 1];
@@ -109,15 +109,20 @@ static int request(ddns_t *ctx, ddns_inf
 		}
 		free(buf);
 
-		if (!hash)
+		if (!hash) {
+                        errmsg = trans.p_rsp_body;
 			rc = RC_DYNDNS_RSP_NOTOK;
-		else
+		} else
 			hash++;
 	}
 	while (0);
 
 	if (rc) {
-		logit(LOG_INFO, "Update URL query failed");
+                if (errmsg != NULL) {
+		        logit(LOG_INFO, "Update URL query failed (%s)", errmsg);
+                } else {
+		        logit(LOG_INFO, "Update URL query failed");
+                }
 		return 0;
 	}
 
