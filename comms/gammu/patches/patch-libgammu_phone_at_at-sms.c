$NetBSD: patch-libgammu_phone_at_at-sms.c,v 1.5 2026/08/21 11:52:39 adam Exp $

Don't use strcharnul from the helper library, it doesn't end 
up as PIC when compiled with Clang.

--- libgammu/phone/at/at-sms.c.orig	2026-08-19 10:48:50.000000000 +0000
+++ libgammu/phone/at/at-sms.c
@@ -118,6 +118,9 @@ GSM_Error ATGEN_ReplyGetSMSMemories(GSM_
 		if (pos_start != NULL) {
 			/* Detect which memories we can use for saving */
 			pos_end = strchrnul(pos_start + 1, ')');
+			pos_end = strchr(pos_start + 1, ')');
+			if (pos_end == NULL)
+				pos_end = pos_start + strlen(pos_start);
 			pos_tmp = strstr(pos_start, "\"SM\"");
 
 			if (pos_tmp != NULL && pos_tmp < pos_end) {
