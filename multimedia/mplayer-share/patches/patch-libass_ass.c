$NetBSD: patch-libass_ass.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libass/ass.c.orig	2025-10-08 03:41:48.351308777 +0000
+++ libass/ass.c
@@ -580,7 +580,7 @@ static int process_info_line(ASS_Track *
         track->YCbCrMatrix = parse_ycbcr_matrix(str + 13);
     } else if (!strncmp(str, "Language:", 9)) {
         char *p = str + 9;
-        while (*p && isspace(*p)) p++;
+        while (*p && isspace((unsigned char)(*p))) p++;
         track->Language = malloc(3);
         strncpy(track->Language, p, 2);
         track->Language[2] = 0;
