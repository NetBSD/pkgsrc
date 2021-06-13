$NetBSD: patch-main_bridge__basic.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/bridge_basic.c.orig	2018-05-07 17:25:08.340535041 +0000
+++ main/bridge_basic.c
@@ -167,7 +167,7 @@ static int build_dtmf_features(struct as
 	size_t number_of_missing_features = 0;
 
 	for (feature = features; *feature; feature++) {
-		if (!isupper(*feature)) {
+		if (!isupper((unsigned char)*feature)) {
 			ast_log(LOG_ERROR, "Features string '%s' rejected because it contains non-uppercase feature.\n", features);
 			return -1;
 		}
