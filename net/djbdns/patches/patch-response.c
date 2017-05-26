$NetBSD: patch-response.c,v 1.1 2017/05/26 15:16:45 schmonz Exp $

Fix the security hole found by Matthew Dempsky.

--- response.c.orig	2001-02-11 16:11:45.000000000 -0500
+++ response.c
@@ -34,7 +34,7 @@ int response_addname(const char *d)
         uint16_pack_big(buf,49152 + name_ptr[i]);
         return response_addbytes(buf,2);
       }
-    if (dlen <= 128)
+    if ((dlen <= 128) && (response_len < 16384))
       if (name_num < NAMES) {
 	byte_copy(name[name_num],dlen,d);
 	name_ptr[name_num] = response_len;
