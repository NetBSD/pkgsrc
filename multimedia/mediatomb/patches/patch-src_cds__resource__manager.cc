$NetBSD: patch-src_cds__resource__manager.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

Support SONY Bravia
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/cds_resource_manager.cc.orig	2010-03-25 14:58:11.000000000 +0000
+++ src/cds_resource_manager.cc
@@ -459,6 +459,29 @@ void CdsResourceManager::addResources(Re
                         extend = _(D_PROFILE) + "=" + D_JPEG_LRG+";";
                 }
             }
+		// Add extended protocol information on filse
+		// need to be transcoded // horipiri
+		else if (strstr(mimeType.c_str(),"video/mpeg"))
+		{
+		    extend = _(D_PROFILE) + "=" + D_MPEG_PS_NTSC + ";";
+		}
+		//else if (strstr(mimeType.c_str(),"audio/mp3"))
+		else if (strstr(mimeType.c_str(),"audio/mpeg"))
+		{
+		    extend = _(D_PROFILE) + "=" + "MP3" + ";";
+		}
+		    else if (strstr(mimeType.c_str(),"audio/L16"))
+		{
+		    extend = _(D_PROFILE) + "=" + "LPCM" + ";";
+		}
+		/*
+		else if (strstr(mimeType.c_str(),"video/vnd.dlna.mpeg-tts"))
+		{
+		    extend = _(D_PROFILE) + "=" + "MPEG_TS_SD_60_AC3_T" + ";";
+		    log_debug("ts HIT!!\n");
+		}
+		log_debug("###mimeType: %s\n", mimeType.c_str());
+		*/
 
 #ifdef EXTERNAL_TRANSCODING
         // we do not support seeking at all, so 00
