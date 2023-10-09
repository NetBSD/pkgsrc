$NetBSD: patch-cd.c,v 1.1 2023/10/09 17:35:38 wiz Exp $

Fix for CVE-2023-43641.

--- cd.c.orig	2018-05-02 00:51:51.000000000 +0000
+++ cd.c
@@ -339,7 +339,7 @@ track_get_rem(const Track* track)
 
 void track_set_index(Track *track, int i, long ind)
 {
-	if (i > MAXINDEX) {
+	if (i < 0 || i > MAXINDEX) {
 		fprintf(stderr, "too many indexes\n");
                 return;
         }
