$NetBSD: patch-src_rsn__supp_wpa.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/rsn_supp/wpa.c.orig	2017-10-16 10:07:14.696331509 +0000
+++ src/rsn_supp/wpa.c
@@ -2440,6 +2440,9 @@ void wpa_sm_notify_disassoc(struct wpa_s
 #ifdef CONFIG_TDLS
 	wpa_tdls_disassoc(sm);
 #endif /* CONFIG_TDLS */
+#ifdef CONFIG_IEEE80211R
+	sm->ft_reassoc_completed = 0;
+#endif /* CONFIG_IEEE80211R */
 
 	/* Keys are not needed in the WPA state machine anymore */
 	wpa_sm_drop_sa(sm);
