$NetBSD: patch-apps_snmpusm.c,v 1.1 2018/02/25 18:35:30 wiz Exp $

From: Andreas Henriksson <andreas@fatal.se>
Date: Sat, 23 Dec 2017 22:25:41 +0000
Subject: [PATCH] Port OpenSSL 1.1.0 with support for 1.0.2

Initial support for OpenSSL 1.1.0

Changes by sebastian@breakpoint.cc:
- added OpenSSL 1.0.2 glue layer for backwarts compatibility
- dropped HAVE_EVP_MD_CTX_CREATE + DESTROY and added a check for OpenSSL
  version instead (and currently 1.0.2 is the only one supported).

BTS: https://bugs.debian.org/828449
Signed-off-by: Sebastian Andrzej Siewior <sebastian@breakpoint.cc>
---
 apps/snmpusm.c              |   43 ++++++++++++++++++++++++++++++++++++-------
 configure.d/config_os_libs2 |    6 ------
 snmplib/keytools.c          |   13 ++++++-------
 snmplib/scapi.c             |   17 +++++------------
 4 files changed, 47 insertions(+), 32 deletions(-)


--- apps/snmpusm.c.orig	2018-02-25 18:04:17.011901242 +0000
+++ apps/snmpusm.c
@@ -183,6 +183,31 @@ setup_oid(oid * it, size_t * len, u_char
 }
 
 #if defined(HAVE_OPENSSL_DH_H) && defined(HAVE_LIBCRYPTO)
+
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+
+static void DH_get0_pqg(const DH *dh,
+			const BIGNUM **p, const BIGNUM **q, const BIGNUM **g)
+{
+	if (p != NULL)
+		*p = dh->p;
+	if (q != NULL)
+		*q = dh->q;
+	if (g != NULL)
+		*g = dh->g;
+}
+
+static void DH_get0_key(const DH *dh, const BIGNUM **pub_key,
+			const BIGNUM **priv_key)
+{
+	if (pub_key != NULL)
+		*pub_key = dh->pub_key;
+	if (priv_key != NULL)
+		*priv_key = dh->priv_key;
+}
+
+#endif
+
 int
 get_USM_DH_key(netsnmp_variable_list *vars, netsnmp_variable_list *dhvar,
                size_t outkey_len,
@@ -190,7 +215,7 @@ get_USM_DH_key(netsnmp_variable_list *va
                oid *keyoid, size_t keyoid_len) {
     u_char *dhkeychange;
     DH *dh;
-    BIGNUM *other_pub;
+    const BIGNUM *p, *g, *pub_key, *other_pub;
     u_char *key;
     size_t key_len;
             
@@ -205,25 +230,29 @@ get_USM_DH_key(netsnmp_variable_list *va
         dh = d2i_DHparams(NULL, &cp, dhvar->val_len);
     }
 
-    if (!dh || !dh->g || !dh->p) {
+    if (dh)
+        DH_get0_pqg(dh, &p, NULL, &g);
+
+    if (!dh || !g || !p) {
         SNMP_FREE(dhkeychange);
         return SNMPERR_GENERR;
     }
 
-    DH_generate_key(dh);
-    if (!dh->pub_key) {
+    if (!DH_generate_key(dh)) {
         SNMP_FREE(dhkeychange);
         return SNMPERR_GENERR;
     }
             
-    if (vars->val_len != (unsigned int)BN_num_bytes(dh->pub_key)) {
+    DH_get0_key(dh, &pub_key, NULL);
+
+    if (vars->val_len != (unsigned int)BN_num_bytes(pub_key)) {
         SNMP_FREE(dhkeychange);
         fprintf(stderr,"incorrect diffie-helman lengths (%lu != %d)\n",
-                (unsigned long)vars->val_len, BN_num_bytes(dh->pub_key));
+                (unsigned long)vars->val_len, BN_num_bytes(pub_key));
         return SNMPERR_GENERR;
     }
 
-    BN_bn2bin(dh->pub_key, dhkeychange + vars->val_len);
+    BN_bn2bin(pub_key, dhkeychange + vars->val_len);
 
     key_len = DH_size(dh);
     if (!key_len) {
