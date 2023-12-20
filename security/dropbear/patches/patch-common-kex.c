$NetBSD: patch-common-kex.c,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- common-kex.c.orig	2022-11-14 14:30:00.000000000 +0000
+++ common-kex.c
@@ -183,6 +183,10 @@ void send_msg_newkeys() {
 	gen_new_keys();
 	switch_keys();
 
+	if (ses.kexstate.strict_kex) {
+		ses.transseq = 0;
+	}
+
 	TRACE(("leave send_msg_newkeys"))
 }
 
@@ -193,7 +197,11 @@ void recv_msg_newkeys() {
 
 	ses.kexstate.recvnewkeys = 1;
 	switch_keys();
-	
+
+	if (ses.kexstate.strict_kex) {
+		ses.recvseq = 0;
+	}
+
 	TRACE(("leave recv_msg_newkeys"))
 }
 
@@ -550,6 +558,10 @@ void recv_msg_kexinit() {
 
 	ses.kexstate.recvkexinit = 1;
 
+	if (ses.kexstate.strict_kex && !ses.kexstate.donefirstkex && ses.recvseq != 1) {
+		dropbear_exit("First packet wasn't kexinit");
+	}
+
 	TRACE(("leave recv_msg_kexinit"))
 }
 
@@ -859,6 +871,18 @@ static void read_kex_algos() {
 	}
 #endif
 
+	if (!ses.kexstate.donefirstkex) {
+		const char* strict_name;
+		if (IS_DROPBEAR_CLIENT) {
+			strict_name = SSH_STRICT_KEX_S;
+		} else {
+			strict_name = SSH_STRICT_KEX_C;
+		}
+		if (buf_has_algo(ses.payload, strict_name) == DROPBEAR_SUCCESS) {
+			ses.kexstate.strict_kex = 1;
+		}
+	}
+
 	algo = buf_match_algo(ses.payload, sshkex, kexguess2, &goodguess);
 	allgood &= goodguess;
 	if (algo == NULL || algo->data == NULL) {
