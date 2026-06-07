$NetBSD: patch-cmac__nettle.c,v 1.1 2026/06/07 17:36:03 adam Exp $

Add support for Nettle 4.0
https://gitlab.com/chrony/chrony/-/commit/fee12ec914cce805cc704a4c2804d75b4933ad2f

--- cmac_nettle.c.orig	2025-08-27 12:05:31.000000000 +0000
+++ cmac_nettle.c
@@ -30,8 +30,10 @@
 #include "sysincl.h"
 
 #include <nettle/cmac.h>
+#include <nettle/version.h>
 
 #include "cmac.h"
+#include "hash.h"
 #include "memory.h"
 
 struct CMC_Instance_Record {
@@ -86,25 +88,39 @@ CMC_CreateInstance(CMC_Algorithm algorit
 int
 CMC_Hash(CMC_Instance inst, const void *in, int in_len, unsigned char *out, int out_len)
 {
+  unsigned char buf[MAX_HASH_LENGTH];
+
   if (in_len < 0 || out_len < 0)
     return 0;
 
   if (out_len > CMAC128_DIGEST_SIZE)
     out_len = CMAC128_DIGEST_SIZE;
 
+  assert(CMAC128_DIGEST_SIZE <= sizeof (buf));
+
   switch (inst->key_length) {
     case AES128_KEY_SIZE:
       cmac_aes128_update(&inst->context.aes128, in_len, in);
-      cmac_aes128_digest(&inst->context.aes128, out_len, out);
+      cmac_aes128_digest(&inst->context.aes128,
+#if NETTLE_VERSION_MAJOR < 4
+                         CMAC128_DIGEST_SIZE,
+#endif
+                         buf);
       break;
     case AES256_KEY_SIZE:
       cmac_aes256_update(&inst->context.aes256, in_len, in);
-      cmac_aes256_digest(&inst->context.aes256, out_len, out);
+      cmac_aes256_digest(&inst->context.aes256,
+#if NETTLE_VERSION_MAJOR < 4
+                         CMAC128_DIGEST_SIZE,
+#endif
+                         buf);
       break;
     default:
       assert(0);
   }
 
+  memcpy(out, buf, out_len);
+
   return out_len;
 }
 
