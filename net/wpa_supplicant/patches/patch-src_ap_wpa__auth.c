$NetBSD: patch-src_ap_wpa__auth.c,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/ap/wpa_auth.c.orig	2017-10-16 10:06:59.832697934 +0000
+++ src/ap/wpa_auth.c
@@ -1901,6 +1901,21 @@ SM_STATE(WPA_PTK, AUTHENTICATION2)
 }
 
 
+static int wpa_auth_sm_ptk_update(struct wpa_state_machine *sm)
+{
+	if (random_get_bytes(sm->ANonce, WPA_NONCE_LEN)) {
+		wpa_printf(MSG_ERROR,
+			   "WPA: Failed to get random data for ANonce");
+		sm->Disconnect = TRUE;
+		return -1;
+	}
+	wpa_hexdump(MSG_DEBUG, "WPA: Assign new ANonce", sm->ANonce,
+		    WPA_NONCE_LEN);
+	sm->TimeoutCtr = 0;
+	return 0;
+}
+
+
 SM_STATE(WPA_PTK, INITPMK)
 {
 	u8 msk[2 * PMK_LEN];
@@ -2458,9 +2473,12 @@ SM_STEP(WPA_PTK)
 		SM_ENTER(WPA_PTK, AUTHENTICATION);
 	else if (sm->ReAuthenticationRequest)
 		SM_ENTER(WPA_PTK, AUTHENTICATION2);
-	else if (sm->PTKRequest)
-		SM_ENTER(WPA_PTK, PTKSTART);
-	else switch (sm->wpa_ptk_state) {
+	else if (sm->PTKRequest) {
+		if (wpa_auth_sm_ptk_update(sm) < 0)
+			SM_ENTER(WPA_PTK, DISCONNECTED);
+		else
+			SM_ENTER(WPA_PTK, PTKSTART);
+	} else switch (sm->wpa_ptk_state) {
 	case WPA_PTK_INITIALIZE:
 		break;
 	case WPA_PTK_DISCONNECT:
