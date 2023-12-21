$NetBSD: patch-src_kex.c,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/kex.c.orig	2023-05-22 19:30:17.000000000 +0000
+++ src/kex.c
@@ -3037,6 +3037,13 @@ kex_method_extension_negotiation = {
     0,
 };
 
+static const LIBSSH2_KEX_METHOD
+kex_method_strict_client_extension = {
+    "kex-strict-c-v00@openssh.com",
+    NULL,
+    0,
+};
+
 static const LIBSSH2_KEX_METHOD *libssh2_kex_methods[] = {
 #if LIBSSH2_ED25519
     &kex_method_ssh_curve25519_sha256,
@@ -3055,6 +3062,7 @@ static const LIBSSH2_KEX_METHOD *libssh2
     &kex_method_diffie_helman_group1_sha1,
     &kex_method_diffie_helman_group_exchange_sha1,
     &kex_method_extension_negotiation,
+    &kex_method_strict_client_extension,
     NULL
 };
 
@@ -3307,13 +3315,13 @@ static int kexinit(LIBSSH2_SESSION * ses
     return 0;
 }
 
-/* kex_agree_instr
+/* _libssh2_kex_agree_instr
  * Kex specific variant of strstr()
  * Needle must be preceded by BOL or ',', and followed by ',' or EOL
  */
-static unsigned char *
-kex_agree_instr(unsigned char *haystack, size_t haystack_len,
-                const unsigned char *needle, size_t needle_len)
+unsigned char *
+_libssh2_kex_agree_instr(unsigned char *haystack, size_t haystack_len,
+                         const unsigned char *needle, size_t needle_len)
 {
     unsigned char *s;
     unsigned char *end_haystack;
@@ -3398,7 +3406,7 @@ static int kex_agree_hostkey(LIBSSH2_SES
         while(s && *s) {
             unsigned char *p = (unsigned char *) strchr((char *) s, ',');
             size_t method_len = (p ? (size_t)(p - s) : strlen((char *) s));
-            if(kex_agree_instr(hostkey, hostkey_len, s, method_len)) {
+            if(_libssh2_kex_agree_instr(hostkey, hostkey_len, s, method_len)) {
                 const LIBSSH2_HOSTKEY_METHOD *method =
                     (const LIBSSH2_HOSTKEY_METHOD *)
                     kex_get_method_by_name((char *) s, method_len,
@@ -3432,9 +3440,9 @@ static int kex_agree_hostkey(LIBSSH2_SES
     }
 
     while(hostkeyp && (*hostkeyp) && (*hostkeyp)->name) {
-        s = kex_agree_instr(hostkey, hostkey_len,
-                            (unsigned char *) (*hostkeyp)->name,
-                            strlen((*hostkeyp)->name));
+        s = _libssh2_kex_agree_instr(hostkey, hostkey_len,
+                                     (unsigned char *) (*hostkeyp)->name,
+                                     strlen((*hostkeyp)->name));
         if(s) {
             /* So far so good, but does it suit our purposes? (Encrypting vs
                Signing) */
@@ -3468,6 +3476,12 @@ static int kex_agree_kex_hostkey(LIBSSH2
 {
     const LIBSSH2_KEX_METHOD **kexp = libssh2_kex_methods;
     unsigned char *s;
+    const unsigned char *strict =
+        (unsigned char *)"kex-strict-s-v00@openssh.com";
+
+    if(_libssh2_kex_agree_instr(kex, kex_len, strict, 28)) {
+        session->kex_strict = 1;
+    }
 
     if(session->kex_prefs) {
         s = (unsigned char *) session->kex_prefs;
@@ -3475,7 +3489,7 @@ static int kex_agree_kex_hostkey(LIBSSH2
         while(s && *s) {
             unsigned char *q, *p = (unsigned char *) strchr((char *) s, ',');
             size_t method_len = (p ? (size_t)(p - s) : strlen((char *) s));
-            q = kex_agree_instr(kex, kex_len, s, method_len);
+            q = _libssh2_kex_agree_instr(kex, kex_len, s, method_len);
             if(q) {
                 const LIBSSH2_KEX_METHOD *method = (const LIBSSH2_KEX_METHOD *)
                     kex_get_method_by_name((char *) s, method_len,
@@ -3509,9 +3523,9 @@ static int kex_agree_kex_hostkey(LIBSSH2
     }
 
     while(*kexp && (*kexp)->name) {
-        s = kex_agree_instr(kex, kex_len,
-                            (unsigned char *) (*kexp)->name,
-                            strlen((*kexp)->name));
+        s = _libssh2_kex_agree_instr(kex, kex_len,
+                                     (unsigned char *) (*kexp)->name,
+                                     strlen((*kexp)->name));
         if(s) {
             /* We've agreed on a key exchange method,
              * Can we agree on a hostkey that works with this kex?
@@ -3555,7 +3569,7 @@ static int kex_agree_crypt(LIBSSH2_SESSI
             unsigned char *p = (unsigned char *) strchr((char *) s, ',');
             size_t method_len = (p ? (size_t)(p - s) : strlen((char *) s));
 
-            if(kex_agree_instr(crypt, crypt_len, s, method_len)) {
+            if(_libssh2_kex_agree_instr(crypt, crypt_len, s, method_len)) {
                 const LIBSSH2_CRYPT_METHOD *method =
                     (const LIBSSH2_CRYPT_METHOD *)
                     kex_get_method_by_name((char *) s, method_len,
@@ -3577,9 +3591,9 @@ static int kex_agree_crypt(LIBSSH2_SESSI
     }
 
     while(*cryptp && (*cryptp)->name) {
-        s = kex_agree_instr(crypt, crypt_len,
-                            (unsigned char *) (*cryptp)->name,
-                            strlen((*cryptp)->name));
+        s = _libssh2_kex_agree_instr(crypt, crypt_len,
+                                     (unsigned char *) (*cryptp)->name,
+                                     strlen((*cryptp)->name));
         if(s) {
             endpoint->crypt = *cryptp;
             return 0;
@@ -3619,7 +3633,7 @@ static int kex_agree_mac(LIBSSH2_SESSION
             unsigned char *p = (unsigned char *) strchr((char *) s, ',');
             size_t method_len = (p ? (size_t)(p - s) : strlen((char *) s));
 
-            if(kex_agree_instr(mac, mac_len, s, method_len)) {
+            if(_libssh2_kex_agree_instr(mac, mac_len, s, method_len)) {
                 const LIBSSH2_MAC_METHOD *method = (const LIBSSH2_MAC_METHOD *)
                     kex_get_method_by_name((char *) s, method_len,
                                            (const LIBSSH2_COMMON_METHOD **)
@@ -3640,8 +3654,9 @@ static int kex_agree_mac(LIBSSH2_SESSION
     }
 
     while(*macp && (*macp)->name) {
-        s = kex_agree_instr(mac, mac_len, (unsigned char *) (*macp)->name,
-                            strlen((*macp)->name));
+        s = _libssh2_kex_agree_instr(mac, mac_len,
+                                     (unsigned char *) (*macp)->name,
+                                     strlen((*macp)->name));
         if(s) {
             endpoint->mac = *macp;
             return 0;
@@ -3672,7 +3687,7 @@ static int kex_agree_comp(LIBSSH2_SESSIO
             unsigned char *p = (unsigned char *) strchr((char *) s, ',');
             size_t method_len = (p ? (size_t)(p - s) : strlen((char *) s));
 
-            if(kex_agree_instr(comp, comp_len, s, method_len)) {
+            if(_libssh2_kex_agree_instr(comp, comp_len, s, method_len)) {
                 const LIBSSH2_COMP_METHOD *method =
                     (const LIBSSH2_COMP_METHOD *)
                     kex_get_method_by_name((char *) s, method_len,
@@ -3694,8 +3709,9 @@ static int kex_agree_comp(LIBSSH2_SESSIO
     }
 
     while(*compp && (*compp)->name) {
-        s = kex_agree_instr(comp, comp_len, (unsigned char *) (*compp)->name,
-                            strlen((*compp)->name));
+        s = _libssh2_kex_agree_instr(comp, comp_len,
+                                     (unsigned char *) (*compp)->name,
+                                     strlen((*compp)->name));
         if(s) {
             endpoint->comp = *compp;
             return 0;
@@ -3876,6 +3892,7 @@ _libssh2_kex_exchange(LIBSSH2_SESSION * 
                 session->local.kexinit = key_state->oldlocal;
                 session->local.kexinit_len = key_state->oldlocal_len;
                 key_state->state = libssh2_NB_state_idle;
+                session->state &= ~LIBSSH2_STATE_INITIAL_KEX;
                 session->state &= ~LIBSSH2_STATE_KEX_ACTIVE;
                 session->state &= ~LIBSSH2_STATE_EXCHANGING_KEYS;
                 return -1;
@@ -3901,6 +3918,7 @@ _libssh2_kex_exchange(LIBSSH2_SESSION * 
                 session->local.kexinit = key_state->oldlocal;
                 session->local.kexinit_len = key_state->oldlocal_len;
                 key_state->state = libssh2_NB_state_idle;
+                session->state &= ~LIBSSH2_STATE_INITIAL_KEX;
                 session->state &= ~LIBSSH2_STATE_KEX_ACTIVE;
                 session->state &= ~LIBSSH2_STATE_EXCHANGING_KEYS;
                 return -1;
@@ -3949,6 +3967,7 @@ _libssh2_kex_exchange(LIBSSH2_SESSION * 
         session->remote.kexinit = NULL;
     }
 
+    session->state &= ~LIBSSH2_STATE_INITIAL_KEX;
     session->state &= ~LIBSSH2_STATE_KEX_ACTIVE;
     session->state &= ~LIBSSH2_STATE_EXCHANGING_KEYS;
 
