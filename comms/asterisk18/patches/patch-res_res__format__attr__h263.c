$NetBSD: patch-res_res__format__attr__h263.c,v 1.1 2024/02/19 05:59:52 jnemeth Exp $

--- res/res_format_attr_h263.c.orig	2022-04-14 21:53:34.000000000 +0000
+++ res/res_format_attr_h263.c
@@ -180,7 +180,7 @@ static struct ast_format *h263_parse_sdp
 
 	/* upper-case everything, so we are case-insensitive */
 	for (attrib = attribs; *attrib; ++attrib) {
-		*attrib = toupper(*attrib);
+		*attrib = toupper((unsigned char)*attrib);
 	} /* based on channels/chan_sip.c:process_a_sdp_image() */
 
 	attr->BPP = H263_ATTR_KEY_UNSET;
