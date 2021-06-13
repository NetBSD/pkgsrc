$NetBSD: patch-main_indications.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/indications.c.orig	2021-03-04 16:46:08.000000000 +0000
+++ main/indications.c
@@ -908,7 +908,7 @@ static void store_tone_zone_ring_cadence
 
 		ring = ast_strip(ring);
 
-		if (!isdigit(ring[0]) || (value = atoi(ring)) == -1) {
+		if (!isdigit((unsigned char)ring[0]) || (value = atoi(ring)) == -1) {
 			ast_log(LOG_WARNING, "Invalid ringcadence given '%s'.\n", ring);
 			continue;
 		}
