$NetBSD: patch-snmplib_scapi.c,v 1.1 2018/02/25 18:35:30 wiz Exp $

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

--- snmplib/scapi.c.orig	2018-02-25 18:04:17.013625332 +0000
+++ snmplib/scapi.c
@@ -486,15 +486,10 @@ sc_hash(const oid * hashtype, size_t has
     }
 
 /** initialize the pointer */
-#ifdef HAVE_EVP_MD_CTX_CREATE
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     cptr = EVP_MD_CTX_create();
 #else
-    cptr = malloc(sizeof(*cptr));
-#if defined(OLD_DES)
-    memset(cptr, 0, sizeof(*cptr));
-#else
-    EVP_MD_CTX_init(cptr);
-#endif
+    cptr = EVP_MD_CTX_new();
 #endif
     if (!EVP_DigestInit(cptr, hashfn)) {
         /* requested hash function is not available */
@@ -507,13 +502,11 @@ sc_hash(const oid * hashtype, size_t has
 /** do the final pass */
     EVP_DigestFinal(cptr, MAC, &tmp_len);
     *MAC_len = tmp_len;
-#ifdef HAVE_EVP_MD_CTX_DESTROY
+
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     EVP_MD_CTX_destroy(cptr);
 #else
-#if !defined(OLD_DES)
-    EVP_MD_CTX_cleanup(cptr);
-#endif
-    free(cptr);
+    EVP_MD_CTX_free(cptr);
 #endif
     return (rval);
 
