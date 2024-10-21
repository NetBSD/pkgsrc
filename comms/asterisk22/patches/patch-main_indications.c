$NetBSD: patch-main_indications.c,v 1.1 2024/10/21 05:12:47 jnemeth Exp $

--- main/indications.c.orig	2021-03-04 16:46:08.000000000 +0000
+++ main/indications.c
@@ -908,7 +908,7 @@ static void store_tone_zone_ring_cadence
 
 		ring = ast_strip(ring);
 
-		if (!isdigit(ring[0]) || (value = atoi(ring)) == -1) {
+		if (!isdigit((unsigned char)ring[0]) || (value = atoi(ring)) == -1) {
 			ast_log(LOG_WARNING, "Invalid ringcadence given '%s'.\n", ring);
 			continue;
 		}
