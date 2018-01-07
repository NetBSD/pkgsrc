$NetBSD: patch-src_nettls-nettle.c,v 1.1 2018/01/07 21:01:09 joerg Exp $

Newer nettle versions provide macros for this purpose.

--- src/nettls-gnutls/nettle.c.orig	2017-08-14 13:16:50.-06639040 +0000
+++ src/nettls-gnutls/nettle.c
@@ -98,7 +98,7 @@ static const char *net_nettle_cipher_nam
     return cipher->name;
 }
 
-#ifndef HAVE_FUN_nettle_ciphers
+#if !defined(HAVE_FUN_nettle_ciphers) && !defined(nettle_ciphers)
 const struct nettle_cipher * const nettle_ciphers[] = {
   &nettle_aes128,
   &nettle_aes192,
@@ -337,7 +337,7 @@ static void net_nettle_hash_digest(net_n
     hash->digest(ctx, length, dst);
 }
 
-#ifndef HAVE_FUN_nettle_hashes
+#if defined(HAVE_FUN_nettle_hashes) && !defined(nettle_hashes)
 const struct nettle_hash * const nettle_hashes[] = {
     &nettle_md2,
     &nettle_md4,
