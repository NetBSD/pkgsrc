$NetBSD: patch-libsauth_src_dkimpublickey.c,v 1.1 2020/03/19 10:52:11 nia Exp $

Fix building with OpenSSL 1.1.

From Yoshihiro Takahashi / FreeBSD Ports.

--- libsauth/src/dkimpublickey.c.orig	2011-11-07 02:09:09.000000000 +0000
+++ libsauth/src/dkimpublickey.c
@@ -398,11 +398,11 @@ DkimPublicKey_build(const DkimPolicyBase
     // compare key type key-k-tag declared and stored in key-p-tag
     switch (self->keytype) {
     case DKIM_KEY_TYPE_RSA:
-        if (EVP_PKEY_RSA != EVP_PKEY_type(self->pkey->type)) {
+        if (EVP_PKEY_RSA != EVP_PKEY_base_id(self->pkey)) {
             DkimLogPermFail
                 (policy,
                  "key-k-tag and key-p-tag doesn't match: domain=%s, keyalg=0x%x, keytype=0x%x",
-                 domain, self->keytype, EVP_PKEY_type(self->pkey->type));
+                 domain, self->keytype, EVP_PKEY_base_id(self->pkey));
             SETDEREF(dstat, DSTAT_PERMFAIL_PUBLICKEY_TYPE_MISMATCH);
             goto cleanup;
         }   // end if
