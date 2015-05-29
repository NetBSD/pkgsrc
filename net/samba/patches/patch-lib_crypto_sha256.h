$NetBSD: patch-lib_crypto_sha256.h,v 1.1 2015/05/29 09:01:09 manu Exp $

Workaroud a conflict between NetBSD libc's and Samva sha2 functions.

--- ../lib/crypto/sha256.h.orig	2015-05-29 10:05:16.000000000 +0200
+++ ../lib/crypto/sha256.h	2015-05-29 10:13:36.000000000 +0200
@@ -41,9 +41,20 @@
    (tridge)
  */
 #define HEIM_SHA_H 1
 
-#if 0
+/*
+ * NetBSD has sha1/sha2 functions built-in libc. The prototype
+ * are the same, but the private context are not. Samba-provided
+ * version must be renamed so that they are not used instead of 
+ * the libc-expected version when going through 
+ * libldap/libssl/libcrypto for ldaps:// connexions.
+ * 
+ * Without this, Samba cannot connect to a LDAP directory that
+ * has a SHA256 certificate. This rather cryptic error is raised:
+ * error:0D0C5006:asn1 encoding routines:ASN1_item_verify:EVP lib
+ */
+#if defined(__NetBSD__)
 /* symbol renaming */
 #define SHA1_Init hc_SHA1_Init
 #define SHA1_Update hc_SHA1_Update
 #define SHA1_Final hc_SHA1_Final
