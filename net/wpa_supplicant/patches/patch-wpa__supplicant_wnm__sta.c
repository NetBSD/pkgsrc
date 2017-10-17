$NetBSD: patch-wpa__supplicant_wnm__sta.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- wpa_supplicant/wnm_sta.c.orig	2016-10-02 18:51:11.000000000 +0000
+++ wpa_supplicant/wnm_sta.c
@@ -260,7 +260,7 @@ static void ieee802_11_rx_wnmsleep_resp(
 
 	if (!wpa_s->wnmsleep_used) {
 		wpa_printf(MSG_DEBUG,
-			   "WNM: Ignore WNM-Sleep Mode Response frame since WNM-Sleep Mode has not been used in this association");
+			   "WNM: Ignore WNM-Sleep Mode Response frame since WNM-Sleep Mode operation has not been requested");
 		return;
 	}
 
@@ -299,6 +299,8 @@ static void ieee802_11_rx_wnmsleep_resp(
 		return;
 	}
 
+	wpa_s->wnmsleep_used = 0;
+
 	if (wnmsleep_ie->status == WNM_STATUS_SLEEP_ACCEPT ||
 	    wnmsleep_ie->status == WNM_STATUS_SLEEP_EXIT_ACCEPT_GTK_UPDATE) {
 		wpa_printf(MSG_DEBUG, "Successfully recv WNM-Sleep Response "
