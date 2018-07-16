$NetBSD: patch-main_indications.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/indications.c.orig	2018-05-07 17:29:02.579091198 +0000
+++ main/indications.c
@@ -904,7 +904,7 @@ static void store_tone_zone_ring_cadence
 
 		ring = ast_strip(ring);
 
-		if (!isdigit(ring[0]) || (val = atoi(ring)) == -1) {
+		if (!isdigit((unsigned char)ring[0]) || (val = atoi(ring)) == -1) {
 			ast_log(LOG_WARNING, "Invalid ringcadence given '%s'.\n", ring);
 			continue;
 		}
