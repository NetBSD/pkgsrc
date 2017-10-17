$NetBSD: patch-src_ap_wpa__auth.h,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/ap/wpa_auth.h.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/ap/wpa_auth.h
@@ -267,7 +267,7 @@ void wpa_receive(struct wpa_authenticato
 		 u8 *data, size_t data_len);
 enum wpa_event {
 	WPA_AUTH, WPA_ASSOC, WPA_DISASSOC, WPA_DEAUTH, WPA_REAUTH,
-	WPA_REAUTH_EAPOL, WPA_ASSOC_FT
+	WPA_REAUTH_EAPOL, WPA_ASSOC_FT, WPA_DRV_STA_REMOVED
 };
 void wpa_remove_ptk(struct wpa_state_machine *sm);
 int wpa_auth_sm_event(struct wpa_state_machine *sm, enum wpa_event event);
@@ -280,6 +280,7 @@ int wpa_auth_pairwise_set(struct wpa_sta
 int wpa_auth_get_pairwise(struct wpa_state_machine *sm);
 int wpa_auth_sta_key_mgmt(struct wpa_state_machine *sm);
 int wpa_auth_sta_wpa_version(struct wpa_state_machine *sm);
+int wpa_auth_sta_ft_tk_already_set(struct wpa_state_machine *sm);
 int wpa_auth_sta_clear_pmksa(struct wpa_state_machine *sm,
 			     struct rsn_pmksa_cache_entry *entry);
 struct rsn_pmksa_cache_entry *
