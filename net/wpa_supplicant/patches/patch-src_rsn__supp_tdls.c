$NetBSD: patch-src_rsn__supp_tdls.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/rsn_supp/tdls.c.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/rsn_supp/tdls.c
@@ -112,6 +112,7 @@ struct wpa_tdls_peer {
 		u8 tk[16]; /* TPK-TK; assuming only CCMP will be used */
 	} tpk;
 	int tpk_set;
+	int tk_set; /* TPK-TK configured to the driver */
 	int tpk_success;
 	int tpk_in_progress;
 
@@ -192,6 +193,20 @@ static int wpa_tdls_set_key(struct wpa_s
 	u8 rsc[6];
 	enum wpa_alg alg;
 
+	if (peer->tk_set) {
+		/*
+		 * This same TPK-TK has already been configured to the driver
+		 * and this new configuration attempt (likely due to an
+		 * unexpected retransmitted frame) would result in clearing
+		 * the TX/RX sequence number which can break security, so must
+		 * not allow that to happen.
+		 */
+		wpa_printf(MSG_INFO, "TDLS: TPK-TK for the peer " MACSTR
+			   " has already been configured to the driver - do not reconfigure",
+			   MAC2STR(peer->addr));
+		return -1;
+	}
+
 	os_memset(rsc, 0, 6);
 
 	switch (peer->cipher) {
@@ -209,12 +224,15 @@ static int wpa_tdls_set_key(struct wpa_s
 		return -1;
 	}
 
+	wpa_printf(MSG_DEBUG, "TDLS: Configure pairwise key for peer " MACSTR,
+		   MAC2STR(peer->addr));
 	if (wpa_sm_set_key(sm, alg, peer->addr, -1, 1,
 			   rsc, sizeof(rsc), peer->tpk.tk, key_len) < 0) {
 		wpa_printf(MSG_WARNING, "TDLS: Failed to set TPK to the "
 			   "driver");
 		return -1;
 	}
+	peer->tk_set = 1;
 	return 0;
 }
 
@@ -696,7 +714,7 @@ static void wpa_tdls_peer_clear(struct w
 	peer->cipher = 0;
 	peer->qos_info = 0;
 	peer->wmm_capable = 0;
-	peer->tpk_set = peer->tpk_success = 0;
+	peer->tk_set = peer->tpk_set = peer->tpk_success = 0;
 	peer->chan_switch_enabled = 0;
 	os_memset(&peer->tpk, 0, sizeof(peer->tpk));
 	os_memset(peer->inonce, 0, WPA_NONCE_LEN);
@@ -1159,6 +1177,7 @@ skip_rsnie:
 		wpa_tdls_peer_free(sm, peer);
 		return -1;
 	}
+	peer->tk_set = 0; /* A new nonce results in a new TK */
 	wpa_hexdump(MSG_DEBUG, "TDLS: Initiator Nonce for TPK handshake",
 		    peer->inonce, WPA_NONCE_LEN);
 	os_memcpy(ftie->Snonce, peer->inonce, WPA_NONCE_LEN);
@@ -1751,6 +1770,19 @@ static int wpa_tdls_addset_peer(struct w
 }
 
 
+static int tdls_nonce_set(const u8 *nonce)
+{
+	int i;
+
+	for (i = 0; i < WPA_NONCE_LEN; i++) {
+		if (nonce[i])
+			return 1;
+	}
+
+	return 0;
+}
+
+
 static int wpa_tdls_process_tpk_m1(struct wpa_sm *sm, const u8 *src_addr,
 				   const u8 *buf, size_t len)
 {
@@ -2004,7 +2036,8 @@ skip_rsn:
 	peer->rsnie_i_len = kde.rsn_ie_len;
 	peer->cipher = cipher;
 
-	if (os_memcmp(peer->inonce, ftie->Snonce, WPA_NONCE_LEN) != 0) {
+	if (os_memcmp(peer->inonce, ftie->Snonce, WPA_NONCE_LEN) != 0 ||
+	    !tdls_nonce_set(peer->inonce)) {
 		/*
 		 * There is no point in updating the RNonce for every obtained
 		 * TPK M1 frame (e.g., retransmission due to timeout) with the
@@ -2020,6 +2053,7 @@ skip_rsn:
 				"TDLS: Failed to get random data for responder nonce");
 			goto error;
 		}
+		peer->tk_set = 0; /* A new nonce results in a new TK */
 	}
 
 #if 0
