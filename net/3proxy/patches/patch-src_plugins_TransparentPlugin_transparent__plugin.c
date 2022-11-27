$NetBSD: patch-src_plugins_TransparentPlugin_transparent__plugin.c,v 1.1 2022/11/27 13:14:01 triaxx Exp $

Suppress warning for incompatibility with strdup() return type.

--- src/plugins/TransparentPlugin/transparent_plugin.c.orig	2021-07-01 16:59:57.000000000 +0000
+++ src/plugins/TransparentPlugin/transparent_plugin.c
@@ -63,7 +63,7 @@ static FILTER_ACTION transparent_filter_
 #endif
 	pl->myinet_ntop(*SAFAMILY(&param->req), SAADDR(&param->req), (char *)addrbuf, sizeof(addrbuf));
 	if(param->hostname) pl->freefunc(param->hostname);
-	param->hostname = pl->strdupfunc(addrbuf);
+	param->hostname = (unsigned char *)pl->strdupfunc(addrbuf);
 	param->sinsr = param->req;
 	return PASS;
 }
