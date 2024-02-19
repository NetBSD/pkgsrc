$NetBSD: patch-res_res__format__attr__vp8.c,v 1.1 2024/02/19 05:59:52 jnemeth Exp $

--- res/res_format_attr_vp8.c.orig	2022-04-14 21:53:34.000000000 +0000
+++ res/res_format_attr_vp8.c
@@ -92,7 +92,7 @@ static struct ast_format *vp8_parse_sdp_
 
 	/* lower-case everything, so we are case-insensitive */
 	for (attrib = attribs; *attrib; ++attrib) {
-		*attrib = tolower(*attrib);
+		*attrib = tolower((unsigned char)*attrib);
 	} /* based on channels/chan_sip.c:process_a_sdp_image() */
 
 	if ((kvp = strstr(attribs, "max-fr")) && sscanf(kvp, "max-fr=%30u", &val) == 1) {
