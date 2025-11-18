$NetBSD: patch-libopenarc_arc-canon.c,v 1.1 2025/11/18 14:02:20 manu Exp $

Cope with badly formed input

--- libopenarc/arc-canon.c.orig	2025-11-07 02:15:05.538163024 +0100
+++ libopenarc/arc-canon.c	2025-11-07 02:16:20.165199776 +0100
@@ -2134,18 +2134,22 @@
 	if (tag[0] == '\0')
 		return ARC_STAT_INVALID;
 
 	token = strtok_r(tag, "/", &last);
+	if (token == NULL)
+		return ARC_STAT_INVALID;
+		
 	code = arc_name_to_code(canonicalizations, token);
-
 	if (code == -1)
 		return ARC_STAT_INVALID;
 
 	*hdr_canon = (arc_canon_t) code;
 
 	token = strtok_r(NULL, "/", &last);
-	code = arc_name_to_code(canonicalizations, token);
+	if (token == NULL)
+		return ARC_STAT_INVALID;
 
+	code = arc_name_to_code(canonicalizations, token);
 	if (code == -1)
 		return ARC_STAT_INVALID;
 
 	*body_canon = (arc_canon_t) code;
