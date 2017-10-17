$NetBSD: patch-src_ap_ieee802__11.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/ap/ieee802_11.c.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/ap/ieee802_11.c
@@ -1841,6 +1841,7 @@ static int add_associated_sta(struct hos
 {
 	struct ieee80211_ht_capabilities ht_cap;
 	struct ieee80211_vht_capabilities vht_cap;
+	int set = 1;
 
 	/*
 	 * Remove the STA entry to ensure the STA PS state gets cleared and
@@ -1848,9 +1849,18 @@ static int add_associated_sta(struct hos
 	 * FT-over-the-DS, where a station re-associates back to the same AP but
 	 * skips the authentication flow, or if working with a driver that
 	 * does not support full AP client state.
+	 *
+	 * Skip this if the STA has already completed FT reassociation and the
+	 * TK has been configured since the TX/RX PN must not be reset to 0 for
+	 * the same key.
 	 */
-	if (!sta->added_unassoc)
+	if (!sta->added_unassoc &&
+	    (!(sta->flags & WLAN_STA_AUTHORIZED) ||
+	     !wpa_auth_sta_ft_tk_already_set(sta->wpa_sm))) {
 		hostapd_drv_sta_remove(hapd, sta->addr);
+		wpa_auth_sm_event(sta->wpa_sm, WPA_DRV_STA_REMOVED);
+		set = 0;
+	}
 
 #ifdef CONFIG_IEEE80211N
 	if (sta->flags & WLAN_STA_HT)
@@ -1873,11 +1883,11 @@ static int add_associated_sta(struct hos
 			    sta->flags & WLAN_STA_VHT ? &vht_cap : NULL,
 			    sta->flags | WLAN_STA_ASSOC, sta->qosinfo,
 			    sta->vht_opmode, sta->p2p_ie ? 1 : 0,
-			    sta->added_unassoc)) {
+			    set)) {
 		hostapd_logger(hapd, sta->addr,
 			       HOSTAPD_MODULE_IEEE80211, HOSTAPD_LEVEL_NOTICE,
 			       "Could not %s STA to kernel driver",
-			       sta->added_unassoc ? "set" : "add");
+			       set ? "set" : "add");
 
 		if (sta->added_unassoc) {
 			hostapd_drv_sta_remove(hapd, sta->addr);
