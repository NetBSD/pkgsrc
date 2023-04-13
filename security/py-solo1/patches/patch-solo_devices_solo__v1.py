$NetBSD: patch-solo_devices_solo__v1.py,v 1.1 2023/04/13 13:42:59 wiz Exp $

From 02bb791f3c32c8f93a3f5bc4d256a5a6c77d7528 Mon Sep 17 00:00:00 2001
From: Kendrick Shaw <kms15@case.edu>
Date: Thu, 9 Jun 2022 23:16:43 +0000
Subject: [PATCH] Update to fido2 library 1.0 API

The fido2 library has changed the names of the CTAP1 class to Ctap1 and
the CTAP2 class to Ctap2; this commit updates the solo1-cli code to use
the new names.

--- solo/devices/solo_v1.py.orig	2022-03-08 11:59:14.206628800 +0000
+++ solo/devices/solo_v1.py
@@ -8,8 +8,8 @@ from threading import Event
 
 from fido2.client import Fido2Client
 from fido2.ctap import CtapError
-from fido2.ctap1 import CTAP1
-from fido2.ctap2 import CTAP2
+from fido2.ctap1 import Ctap1
+from fido2.ctap2 import Ctap2
 from fido2.hid import CTAPHID, CtapHidDevice
 from intelhex import IntelHex
 
@@ -64,9 +64,9 @@ class Client(SoloClient):
             dev = devices[0]
         self.dev = dev
 
-        self.ctap1 = CTAP1(dev)
+        self.ctap1 = Ctap1(dev)
         try:
-            self.ctap2 = CTAP2(dev)
+            self.ctap2 = Ctap2(dev)
         except CtapError:
             self.ctap2 = None
 
