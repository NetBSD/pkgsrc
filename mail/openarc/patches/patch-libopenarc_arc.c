$NetBSD: patch-libopenarc_arc.c,v 1.2 2025/06/16 16:17:05 ryoon Exp $

Fix buffer overrun

From upstream
https://github.com/trusteddomainproject/OpenARC/pull/117

--- libopenarc/arc.c.orig	2018-09-21 15:51:23.000000000 +0000
+++ libopenarc/arc.c
@@ -1664,8 +1664,7 @@ arc_process_set(ARC_MESSAGE *msg, arc_kv
 		    arc_param_get(set, (u_char *) "b") == NULL ||
 		    arc_param_get(set, (u_char *) "s") == NULL ||
 		    arc_param_get(set, (u_char *) "d") == NULL ||
-		    arc_param_get(set, (u_char *) "a") == NULL ||
-		    arc_param_get(set, (u_char *) "t") == NULL)
+		    arc_param_get(set, (u_char *) "a") == NULL)
 		{
 			arc_error(msg, "missing parameter(s) in %s data",
 			          settype);
@@ -2330,6 +2329,10 @@ arc_parse_header_field(ARC_MESSAGE *msg,
 	while (end > hdr && isascii(*(end - 1)) && isspace(*(end - 1)))
 		end--;
 
+	/* don't allow incredibly large field names */
+	if (end - hdr > ARC_MAXHEADER)
+		return ARC_STAT_SYNTAX;
+
 	/* don't allow a field name containing a semicolon */
 	semicolon = memchr(hdr, ';', hlen);
 	if (semicolon != NULL && colon != NULL && semicolon < colon)
@@ -2677,6 +2680,7 @@ arc_eoh(ARC_MESSAGE *msg)
 	for (h = msg->arc_hhead; h != NULL; h = h->hdr_next)
 	{
 		char hnbuf[ARC_MAXHEADER + 1];
+		assert(h->hdr_namelen <= ARC_MAXHEADER);
 
 		memset(hnbuf, '\0', sizeof hnbuf);
 		strncpy(hnbuf, h->hdr_text, h->hdr_namelen);
