$NetBSD: patch-src_ap_wpa__auth__i.h,v 1.1 2017/10/16 10:26:21 maya Exp $

--- src/ap/wpa_auth_i.h.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/ap/wpa_auth_i.h
@@ -65,6 +65,7 @@ struct wpa_state_machine {
 	struct wpa_ptk PTK;
 	Boolean PTK_valid;
 	Boolean pairwise_set;
+	Boolean tk_already_set;
 	int keycount;
 	Boolean Pair;
 	struct wpa_key_replay_counter {
