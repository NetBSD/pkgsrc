$NetBSD: patch-snmplib_keytools.c,v 1.1 2018/02/25 18:35:30 wiz Exp $

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

--- snmplib/keytools.c.orig	2018-02-25 18:04:17.012838017 +0000
+++ snmplib/keytools.c
@@ -149,13 +149,13 @@ generate_Ku(const oid * hashtype, u_int 
      */
 #ifdef NETSNMP_USE_OPENSSL
 
-#ifdef HAVE_EVP_MD_CTX_CREATE
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     ctx = EVP_MD_CTX_create();
 #else
-    ctx = malloc(sizeof(*ctx));
-    if (!EVP_MD_CTX_init(ctx))
-        return SNMPERR_GENERR;
+    ctx = EVP_MD_CTX_new();
 #endif
+    if (!ctx)
+        return SNMPERR_GENERR;
 #ifndef NETSNMP_DISABLE_MD5
     if (ISTRANSFORM(hashtype, HMACMD5Auth)) {
         if (!EVP_DigestInit(ctx, EVP_md5()))
@@ -259,11 +259,10 @@ generate_Ku(const oid * hashtype, u_int 
     memset(buf, 0, sizeof(buf));
 #ifdef NETSNMP_USE_OPENSSL
     if (ctx) {
-#ifdef HAVE_EVP_MD_CTX_DESTROY
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
         EVP_MD_CTX_destroy(ctx);
 #else
-        EVP_MD_CTX_cleanup(ctx);
-        free(ctx);
+        EVP_MD_CTX_free(ctx);
 #endif
     }
 #endif
