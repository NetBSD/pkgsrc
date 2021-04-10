$NetBSD: patch-ssh-ecdsa.c,v 1.1 2021/04/10 09:10:11 nia Exp $

Fix segfault when handling ECDSA keys

Import patch by Marc Deslauriers from the Ubuntu package of pam_ssh_agent_auth

Ref: https://github.com/jbeverly/pam_ssh_agent_auth/pull/24/files
     https://github.com/jbeverly/pam_ssh_agent_auth/issues/18
     https://bugs.launchpad.net/ubuntu/+source/pam-ssh-agent-auth/+bug/1869512

--- ssh-ecdsa.c.orig	2019-07-08 16:36:13.000000000 +0000
+++ ssh-ecdsa.c
@@ -46,7 +46,7 @@ ssh_ecdsa_sign(const Key *key, u_char **
     u_int len, dlen;
     Buffer b, bb;
 #if OPENSSL_VERSION_NUMBER >= 0x10100005L
-	BIGNUM *r, *s;
+	BIGNUM *r = NULL, *s = NULL;
 #endif
 
     if (key == NULL || key->type != KEY_ECDSA || key->ecdsa == NULL) {
@@ -137,20 +137,27 @@ ssh_ecdsa_verify(const Key *key, const u
 
     /* parse signature */
     if ((sig = ECDSA_SIG_new()) == NULL)
-        pamsshagentauth_fatal("ssh_ecdsa_verify: DSA_SIG_new failed");
+        pamsshagentauth_fatal("ssh_ecdsa_verify: ECDSA_SIG_new failed");
 
     pamsshagentauth_buffer_init(&b);
     pamsshagentauth_buffer_append(&b, sigblob, len);
 #if OPENSSL_VERSION_NUMBER < 0x10100005L
     if ((pamsshagentauth_buffer_get_bignum2_ret(&b, sig->r) == -1) ||
         (pamsshagentauth_buffer_get_bignum2_ret(&b, sig->s) == -1))
+        pamsshagentauth_fatal("ssh_ecdsa_verify:"
+            "pamsshagentauth_buffer_get_bignum2_ret failed");
 #else
-    DSA_SIG_get0(sig, &r, &s);
+    if ((r = BN_new()) == NULL)
+        pamsshagentauth_fatal("ssh_ecdsa_verify: BN_new failed");
+    if ((s = BN_new()) == NULL)
+        pamsshagentauth_fatal("ssh_ecdsa_verify: BN_new failed");
     if ((pamsshagentauth_buffer_get_bignum2_ret(&b, r) == -1) ||
         (pamsshagentauth_buffer_get_bignum2_ret(&b, s) == -1))
-#endif
         pamsshagentauth_fatal("ssh_ecdsa_verify:"
             "pamsshagentauth_buffer_get_bignum2_ret failed");
+    if (ECDSA_SIG_set0(sig, r, s) != 1)
+        pamsshagentauth_fatal("ssh_ecdsa_verify: ECDSA_SIG_set0 failed");
+#endif
 
     /* clean up */
     memset(sigblob, 0, len);
