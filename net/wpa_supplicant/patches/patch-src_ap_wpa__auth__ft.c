$NetBSD: patch-src_ap_wpa__auth__ft.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/ap/wpa_auth_ft.c.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/ap/wpa_auth_ft.c
@@ -780,6 +780,14 @@ void wpa_ft_install_ptk(struct wpa_state
 		return;
 	}
 
+	if (sm->tk_already_set) {
+		/* Must avoid TK reconfiguration to prevent clearing of TX/RX
+		 * PN in the driver */
+		wpa_printf(MSG_DEBUG,
+			   "FT: Do not re-install same PTK to the driver");
+		return;
+	}
+
 	/* FIX: add STA entry to kernel/driver here? The set_key will fail
 	 * most likely without this.. At the moment, STA entry is added only
 	 * after association has been completed. This function will be called
@@ -792,6 +800,7 @@ void wpa_ft_install_ptk(struct wpa_state
 
 	/* FIX: MLME-SetProtection.Request(TA, Tx_Rx) */
 	sm->pairwise_set = TRUE;
+	sm->tk_already_set = TRUE;
 }
 
 
@@ -898,6 +907,7 @@ static int wpa_ft_process_auth_req(struc
 
 	sm->pairwise = pairwise;
 	sm->PTK_valid = TRUE;
+	sm->tk_already_set = FALSE;
 	wpa_ft_install_ptk(sm);
 
 	buflen = 2 + sizeof(struct rsn_mdie) + 2 + sizeof(struct rsn_ftie) +
