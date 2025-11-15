$NetBSD: patch-stream_stream__dvb.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/stream_dvb.c.orig	2025-10-08 03:53:09.505855180 +0000
+++ stream/stream_dvb.c
@@ -206,7 +206,7 @@ static dvb_channels_list *dvb_get_channe
 		{
 			fields = sscanf(&line[k], sat_conf,
 				&ptr->freq, &ptr->pol, &ptr->diseqc, &ptr->srate, vpid_str, apid_str);
-			ptr->pol = toupper(ptr->pol);
+			ptr->pol = toupper((unsigned char)(ptr->pol));
 			ptr->freq *=  1000UL;
 			ptr->srate *=  1000UL;
 			ptr->tone = -1;
