$NetBSD: patch-libgammu_phone_at_at-sms.c,v 1.4 2023/09/24 00:50:48 manu Exp $

1) Don't use strcharnul from the helper library, it doesn't end 
up as PIC when compiled with Clang.

2) Skip garbage reply on AT+CMGL in PDU mode as in text mode

From upstream https://github.com/gammu/gammu/pull/823

THe D-Link DWM222 4G USB modem sends a garbage line before the reply
to AT+CMGL. This case was handled in text mode but not in PDU mode,
and this device exhibit the bad behavior in PDU mode too.

This change brings garbage skip behavior in PDU mode on par with text mode.

--- libgammu/phone/at/at-sms.c.orig	2019-09-27 10:55:52.000000000 +0200
+++ libgammu/phone/at/at-sms.c	2023-09-24 02:44:57.292835696 +0200
@@ -113,8 +113,11 @@
 		}
 		if (pos_start != NULL) {
 			/* Detect which memories we can use for saving */
 			pos_end = strchrnul(pos_start + 1, ')');
+			pos_end = strchr(pos_start + 1, ')');
+			if (pos_end == NULL)
+				pos_end = pos_start + strlen(pos_start);
 			pos_tmp = strstr(pos_start, "\"SM\"");
 
 			if (pos_tmp != NULL && pos_tmp < pos_end) {
 				Priv->SIMSaveSMS = AT_AVAILABLE;
@@ -1144,14 +1147,9 @@
 		if (str == NULL) {
 			/*
 			 * Sometimes an SMS message will contain a line break. In SMS text
                          * mode we skip to the next line and try again to find +CMGL.
-			 * FIXME: Can we do the same for SMS PDU mode?
 			 */
-			if (Priv->SMSMode == SMS_AT_PDU) {
-				smprintf(s, "Can not find +CMGL:!\n");
-				return ERR_UNKNOWN;
-			}
 			continue;
 		}
 
 		/* Parse reply */
