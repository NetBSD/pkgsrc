$NetBSD: patch-res_res__format__attr__ilbc.c,v 1.1 2024/02/19 05:59:52 jnemeth Exp $

--- res/res_format_attr_ilbc.c.orig	2022-04-14 21:53:34.000000000 +0000
+++ res/res_format_attr_ilbc.c
@@ -87,7 +87,7 @@ static struct ast_format *ilbc_parse_sdp
 
 	/* lower-case everything, so we are case-insensitive */
 	for (attrib = attribs; *attrib; ++attrib) {
-		*attrib = tolower(*attrib);
+		*attrib = tolower((unsigned char)*attrib);
 	} /* based on channels/chan_sip.c:process_a_sdp_image() */
 
 	if ((kvp = strstr(attribs, "mode")) && sscanf(kvp, "mode=%30u", &val) == 1) {
