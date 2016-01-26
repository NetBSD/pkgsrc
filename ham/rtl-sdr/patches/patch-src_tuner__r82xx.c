$NetBSD: patch-src_tuner__r82xx.c,v 1.1 2016/01/26 09:10:39 dbj Exp $

--- src/tuner_r82xx.c.orig	2014-02-07 01:04:24.000000000 +0000
+++ src/tuner_r82xx.c
@@ -547,7 +547,7 @@ static int r82xx_set_pll(struct r82xx_pr
 	}
 
 	if (!(data[2] & 0x40)) {
-		printf("[R82XX] PLL not locked!\n");
+		fprintf(stderr, "[R82XX] PLL not locked!\n");
 		priv->has_lock = 0;
 		return 0;
 	}
