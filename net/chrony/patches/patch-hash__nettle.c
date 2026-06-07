$NetBSD: patch-hash__nettle.c,v 1.1 2026/06/07 17:36:03 adam Exp $

Add support for Nettle 4.0
https://gitlab.com/chrony/chrony/-/commit/fee12ec914cce805cc704a4c2804d75b4933ad2f

--- hash_nettle.c.orig	2025-08-27 12:05:31.000000000 +0000
+++ hash_nettle.c
@@ -30,6 +30,7 @@
 #include "sysincl.h"
 
 #include <nettle/nettle-meta.h>
+#include <nettle/version.h>
 
 #include "hash.h"
 #include "memory.h"
@@ -91,6 +92,7 @@ int
 HSH_Hash(int id, const void *in1, int in1_len, const void *in2, int in2_len,
          unsigned char *out, int out_len)
 {
+  unsigned char buf[MAX_HASH_LENGTH];
   const struct nettle_hash *hash;
   void *context;
 
@@ -103,11 +105,20 @@ HSH_Hash(int id, const void *in1, int in
   if (out_len > hash->digest_size)
     out_len = hash->digest_size;
 
+  if (hash->digest_size > sizeof (buf))
+    return 0;
+
   hash->init(context);
   hash->update(context, in1_len, in1);
   if (in2)
     hash->update(context, in2_len, in2);
-  hash->digest(context, out_len, out);
+  hash->digest(context,
+#if NETTLE_VERSION_MAJOR < 4
+               hash->digest_size,
+#endif
+               buf);
+
+  memcpy(out, buf, out_len);
 
   return out_len;
 }
