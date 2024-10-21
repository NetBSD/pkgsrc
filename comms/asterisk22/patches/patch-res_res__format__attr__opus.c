$NetBSD: patch-res_res__format__attr__opus.c,v 1.1 2024/10/21 05:12:47 jnemeth Exp $

--- res/res_format_attr_opus.c.orig	2022-04-14 22:16:42.000000000 +0000
+++ res/res_format_attr_opus.c
@@ -151,7 +151,7 @@ static struct ast_format *opus_parse_sdp
 
 	/* lower-case everything, so we are case-insensitive */
 	for (attrib = attribs; *attrib; ++attrib) {
-		*attrib = tolower(*attrib);
+		*attrib = tolower((unsigned char)*attrib);
 	} /* based on channels/chan_sip.c:process_a_sdp_image() */
 
 	sdp_fmtp_get(attribs, CODEC_OPUS_ATTR_MAX_PLAYBACK_RATE, &attr->maxplayrate);
