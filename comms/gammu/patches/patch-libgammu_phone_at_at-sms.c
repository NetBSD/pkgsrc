$NetBSD: patch-libgammu_phone_at_at-sms.c,v 1.2 2014/11/23 09:46:50 mef Exp $

Don't use strcharnul from the helper library, it doesn't end up as PIC
when compiled with Clang.

--- libgammu/phone/at/at-sms.c~	2014-11-23 18:13:31.000000000 +0900
+++ libgammu/phone/at/at-sms.c	2014-11-23 18:15:42.000000000 +0900
@@ -112,6 +112,9 @@ GSM_Error ATGEN_ReplyGetSMSMemories(GSM_
 		if (pos_start != NULL) {
 			/* Detect which memories we can use for saving */
 			pos_end = strchrnul(pos_start + 1, ')');
+			pos_end = strchr(pos_start + 1, ')');
+			if (pos_end == NULL)
+				pos_end = pos_start + strlen(pos_start);
 			pos_tmp = strstr(pos_start, "\"SM\"");
 
 			if (pos_tmp != NULL && pos_tmp < pos_end) {
