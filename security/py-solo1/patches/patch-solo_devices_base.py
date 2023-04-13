$NetBSD: patch-solo_devices_base.py,v 1.1 2023/04/13 13:42:59 wiz Exp $

From 02bb791f3c32c8f93a3f5bc4d256a5a6c77d7528 Mon Sep 17 00:00:00 2001
From: Kendrick Shaw <kms15@case.edu>
Date: Thu, 9 Jun 2022 23:16:43 +0000
Subject: [PATCH] Update to fido2 library 1.0 API

The fido2 library has changed the names of the CTAP1 class to Ctap1 and
the CTAP2 class to Ctap2; this commit updates the solo1-cli code to use
the new names.

--- solo/devices/base.py.orig	2022-03-08 11:59:14.206628800 +0000
+++ solo/devices/base.py
@@ -3,7 +3,7 @@ import struct
 from cryptography import x509
 from cryptography.hazmat.backends import default_backend
 from fido2.attestation import Attestation
-from fido2.ctap2 import CTAP2, CredentialManagement
+from fido2.ctap2 import Ctap2, CredentialManagement
 from fido2.hid import CTAPHID
 from fido2.utils import hmac_sha256
 from fido2.webauthn import PublicKeyCredentialCreationOptions
@@ -76,7 +76,7 @@ class SoloClient:
     def reset(
         self,
     ):
-        CTAP2(self.get_current_hid_device()).reset()
+        Ctap2(self.get_current_hid_device()).reset()
 
     def change_pin(self, old_pin, new_pin):
         client = self.get_current_fido_client()
@@ -114,7 +114,7 @@ class SoloClient:
     def cred_mgmt(self, pin):
         client = self.get_current_fido_client()
         token = client.client_pin.get_pin_token(pin)
-        ctap2 = CTAP2(self.get_current_hid_device())
+        ctap2 = Ctap2(self.get_current_hid_device())
         return CredentialManagement(ctap2, client.client_pin.protocol, token)
 
     def enter_solo_bootloader(
@@ -137,11 +137,11 @@ class SoloClient:
         pass
 
     def program_kbd(self, cmd):
-        ctap2 = CTAP2(self.get_current_hid_device())
+        ctap2 = Ctap2(self.get_current_hid_device())
         return ctap2.send_cbor(0x51, cmd)
 
     def sign_hash(self, credential_id, dgst, pin):
-        ctap2 = CTAP2(self.get_current_hid_device())
+        ctap2 = Ctap2(self.get_current_hid_device())
         client = self.get_current_fido_client()
         if pin:
             pin_token = client.client_pin.get_pin_token(pin)
