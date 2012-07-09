$NetBSD: patch-libgammu_phone_at_at-sms.c,v 1.1 2012/07/09 19:17:52 joerg Exp $

--- libgammu/phone/at/at-sms.c.orig	2012-07-06 11:57:04.000000000 +0000
+++ libgammu/phone/at/at-sms.c
@@ -83,7 +83,9 @@ GSM_Error ATGEN_ReplyGetSMSMemories(GSM_
 		}
 		if (pos_start != NULL) {
 			/* Detect which memories we can use for saving */
-			pos_end = strchrnul(pos_start + 1, ')');
+			pos_end = strchr(pos_start + 1, ')');
+			if (pos_end == NULL)
+				pos_end = pos_start + strlen(pos_start);
 			pos_tmp = strstr(pos_start, "\"SM\"");
 			if (pos_tmp != NULL && pos_tmp < pos_end) {
 				s->Phone.Data.Priv.ATGEN.SIMSaveSMS = AT_AVAILABLE;
