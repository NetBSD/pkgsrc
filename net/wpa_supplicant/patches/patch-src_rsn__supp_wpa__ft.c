$NetBSD: patch-src_rsn__supp_wpa__ft.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/rsn_supp/wpa_ft.c.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/rsn_supp/wpa_ft.c
@@ -153,6 +153,7 @@ static u8 * wpa_ft_gen_req_ies(struct wp
 	u16 capab;
 
 	sm->ft_completed = 0;
+	sm->ft_reassoc_completed = 0;
 
 	buf_len = 2 + sizeof(struct rsn_mdie) + 2 + sizeof(struct rsn_ftie) +
 		2 + sm->r0kh_id_len + ric_ies_len + 100;
@@ -681,6 +682,11 @@ int wpa_ft_validate_reassoc_resp(struct 
 		return -1;
 	}
 
+	if (sm->ft_reassoc_completed) {
+		wpa_printf(MSG_DEBUG, "FT: Reassociation has already been completed for this FT protocol instance - ignore unexpected retransmission");
+		return 0;
+	}
+
 	if (wpa_ft_parse_ies(ies, ies_len, &parse) < 0) {
 		wpa_printf(MSG_DEBUG, "FT: Failed to parse IEs");
 		return -1;
@@ -781,6 +787,8 @@ int wpa_ft_validate_reassoc_resp(struct 
 		return -1;
 	}
 
+	sm->ft_reassoc_completed = 1;
+
 	if (wpa_ft_process_gtk_subelem(sm, parse.gtk, parse.gtk_len) < 0)
 		return -1;
 
