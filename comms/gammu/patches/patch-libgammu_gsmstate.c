$NetBSD: patch-libgammu_gsmstate.c,v 1.1 2020/02/15 02:19:49 manu Exp $

Make sure power is enabled on startup. Useful for D-Link DWM-157

From upstream https://github.com/gammu/gammu/pull/516

--- libgammu/gsmstate.c.orig	2019-01-28 16:16:07.000000000 +0100
+++ libgammu/gsmstate.c	2020-02-14 03:16:46.526678044 +0100
@@ -900,8 +900,14 @@
 			GSM_LogError(s, "Init:Phone->GetFirmware" , error);
 			return error;
 		}
 
+		error=s->Phone.Functions->SetPower(s, 1);
+		if (error != ERR_NONE && error != ERR_NOTSUPPORTED) {
+			GSM_LogError(s, "Init:Phone->SetPower" , error);
+			return error;
+		}
+
 		error=s->Phone.Functions->PostConnect(s);
 		if (error != ERR_NONE && error != ERR_NOTSUPPORTED) {
 			GSM_LogError(s, "Init:Phone->PostConnect" , error);
 			return error;
