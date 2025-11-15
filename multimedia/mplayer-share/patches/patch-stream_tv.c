$NetBSD: patch-stream_tv.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/tv.c.orig	2025-10-08 03:54:19.463982928 +0000
+++ stream/tv.c
@@ -575,7 +575,7 @@ static int open_tv(tvi_handle_t *tvh)
 	int channel = 0;
 	if (tvh->tv_param->channel)
 	 {
-	   if (isdigit(*tvh->tv_param->channel))
+	   if (isdigit((unsigned char)(*tvh->tv_param->channel)))
 		/* if tvh->tv_param->channel begins with a digit interpret it as a number */
 		channel = atoi(tvh->tv_param->channel);
 	   else
