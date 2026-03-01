$NetBSD: patch-libagent_gpg_agent.py,v 1.1 2026/03/01 15:09:42 js Exp $

From de6301e9c8d5459be070a472abf85c59998f8c32 Mon Sep 17 00:00:00 2001
From: Roman Zeyde <me@romanzey.de>
Date: Sun, 1 Mar 2026 12:02:24 +0100
Subject: [PATCH] Lookup GnuPG user ID (instead of assuming it's the first one)

--- libagent/gpg/agent.py.orig	2026-03-01 15:03:49.749580195 +0000
+++ libagent/gpg/agent.py
@@ -161,19 +161,26 @@ class Handler:
         keygrip_bytes = binascii.unhexlify(keygrip)
         pubkey_dict, user_ids = decode.load_by_keygrip(
             pubkey_bytes=self.pubkey_bytes, keygrip=keygrip_bytes)
-        # We assume the first user ID is used to generate TREZOR-based GPG keys.
-        user_id = user_ids[0]['value'].decode('utf-8')
+        log.debug("pubkey_dict %s", pubkey_dict)
+
         curve_name = protocol.get_curve_name_by_oid(pubkey_dict['curve_oid'])
         ecdh = pubkey_dict['algo'] == protocol.ECDH_ALGO_ID
 
-        identity = client.create_identity(user_id=user_id, curve_name=curve_name)
-        verifying_key = self.client.pubkey(identity=identity, ecdh=ecdh)
-        pubkey = protocol.PublicKey(
-            curve_name=curve_name, created=pubkey_dict['created'],
-            verifying_key=verifying_key, ecdh=ecdh)
-        assert pubkey.key_id() == pubkey_dict['key_id']
-        assert pubkey.keygrip() == keygrip_bytes
-        return identity
+        # Lookup the first user ID that matches the provided keygrip
+        for user_id_dict in user_ids:
+            log.debug("user_id: %s", user_id_dict)
+            user_id = user_id_dict['value'].decode('utf-8')
+
+            identity = client.create_identity(user_id=user_id, curve_name=curve_name)
+            verifying_key = self.client.pubkey(identity=identity, ecdh=ecdh)
+            pubkey = protocol.PublicKey(
+                curve_name=curve_name, created=pubkey_dict['created'],
+                verifying_key=verifying_key, ecdh=ecdh)
+
+            if pubkey.keygrip() == keygrip_bytes and pubkey.key_id() == pubkey_dict['key_id']:
+                return identity
+
+        raise KeyError(keygrip)
 
     def pksign(self, conn):
         """Sign a message digest using a private EC key."""
