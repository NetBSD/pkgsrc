$NetBSD: patch-src_options.c,v 1.2 2025/12/01 13:34:43 adam Exp $

--- src/options.c.orig	2023-06-15 20:11:10.000000000 +0000
+++ src/options.c
@@ -385,8 +385,8 @@ void get_options(int argc, char **argv,
 	/* Set limits */
 	if (options->rate < 1000)
 		options->rate = 1000;	/* Min. rate 1 kHz */
-	if (options->rate > 48000)
-		options->rate = 48000;	/* Max. rate 48 kHz */
+	if (options->rate > 192000)
+		options->rate = 192000;	/* Max. rate 192 kHz */
 
 	/* apply guess if no driver selected */
 	if (!options->driver_id)
