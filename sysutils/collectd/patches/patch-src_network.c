$NetBSD: patch-src_network.c,v 1.5.2.2 2017/04/08 17:34:36 spz Exp $

Backport fix for CVE-2017-7401.
https://github.com/collectd/collectd/commit/f6be4f9b49b949b379326c3d7002476e6ce4f211

--- src/network.c.orig	2017-01-23 07:53:57.716449156 +0000
+++ src/network.c
@@ -1003,14 +1003,6 @@ static int parse_part_sign_sha256(socken
   buffer_len = *ret_buffer_len;
   buffer_offset = 0;
 
-  if (se->data.server.userdb == NULL) {
-    c_complain(
-        LOG_NOTICE, &complain_no_users,
-        "network plugin: Received signed network packet but can't verify it "
-        "because no user DB has been configured. Will accept it.");
-    return (0);
-  }
-
   /* Check if the buffer has enough data for this structure. */
   if (buffer_len <= PART_SIGNATURE_SHA256_SIZE)
     return (-ENOMEM);
@@ -1027,6 +1019,18 @@ static int parse_part_sign_sha256(socken
     return (-1);
   }
 
+  if (se->data.server.userdb == NULL) {
+    c_complain(
+        LOG_NOTICE, &complain_no_users,
+        "network plugin: Received signed network packet but can't verify it "
+        "because no user DB has been configured. Will accept it.");
+
+    *ret_buffer = buffer + pss_head_length;
+    *ret_buffer_len -= pss_head_length;
+
+    return (0);
+  }
+
   /* Copy the hash. */
   BUFFER_READ(pss.hash, sizeof(pss.hash));
 
