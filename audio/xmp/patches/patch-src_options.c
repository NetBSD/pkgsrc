$NetBSD: patch-src_options.c,v 1.1 2013/12/10 07:14:45 rxg Exp $

--- src/options.c.orig	2013-05-19 14:18:19.000000000 +0000
+++ src/options.c
@@ -317,6 +317,6 @@ void get_options(int argc, char **argv, 
 	/* Set limits */
 	if (options->rate < 1000)
 		options->rate = 1000;	/* Min. rate 1 kHz */
-	if (options->rate > 48000)
-		options->rate = 48000;	/* Max. rate 48 kHz */
+	if (options->rate > 192000)
+		options->rate = 192000;	/* Max. rate 192 kHz */
 }
