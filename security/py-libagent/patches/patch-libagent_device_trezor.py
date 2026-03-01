$NetBSD: patch-libagent_device_trezor.py,v 1.1 2026/03/01 15:09:41 js Exp $

From 29fc6e43abeb8e6da587286c43ec1f8b24d25ec2 Mon Sep 17 00:00:00 2001
From: Roman Zeyde <me@romanzey.de>
Date: Sun, 1 Mar 2026 15:36:50 +0100
Subject: [PATCH] Fix passphrase support on Trezor

--- libagent/device/trezor.py.orig	2026-03-01 15:05:00.329998622 +0000
+++ libagent/device/trezor.py
@@ -3,7 +3,7 @@
 import logging
 
 from trezorlib.btc import get_public_node
-from trezorlib.client import get_default_client, get_default_session
+from trezorlib.client import PassphraseSetting, get_default_client
 from trezorlib.exceptions import TrezorFailure
 from trezorlib.messages import IdentityType
 from trezorlib.misc import get_ecdh_session_key, sign_identity
@@ -37,7 +37,7 @@ class Trezor(interface.Device):
                 pin_callback=self.ui.get_pin,
                 code_entry_callback=self.ui.get_pairing_code,
             )
-            session = client.get_session(passphrase="")  # TODO: support passphrase
+            session = client.get_session(passphrase=PassphraseSetting.AUTO)
             log.info("%s @ fpr=%s", session, session.get_root_fingerprint().hex())
             self.__class__._session = session
 
