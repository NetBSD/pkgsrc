$NetBSD: patch-src_rsn__supp_wpa__i.h,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/rsn_supp/wpa_i.h.orig	2017-10-16 10:07:14.696977884 +0000
+++ src/rsn_supp/wpa_i.h
@@ -128,6 +128,7 @@ struct wpa_sm {
 	size_t r0kh_id_len;
 	u8 r1kh_id[FT_R1KH_ID_LEN];
 	int ft_completed;
+	int ft_reassoc_completed;
 	int over_the_ds_in_progress;
 	u8 target_ap[ETH_ALEN]; /* over-the-DS target AP */
 	int set_ptk_after_assoc;
