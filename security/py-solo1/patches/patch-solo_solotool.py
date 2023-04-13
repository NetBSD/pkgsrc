$NetBSD: patch-solo_solotool.py,v 1.1 2023/04/13 13:42:59 wiz Exp $

From 02bb791f3c32c8f93a3f5bc4d256a5a6c77d7528 Mon Sep 17 00:00:00 2001
From: Kendrick Shaw <kms15@case.edu>
Date: Thu, 9 Jun 2022 23:16:43 +0000
Subject: [PATCH] Update to fido2 library 1.0 API

The fido2 library has changed the names of the CTAP1 class to Ctap1 and
the CTAP2 class to Ctap2; this commit updates the solo1-cli code to use
the new names.

--- solo/solotool.py.orig	2022-03-08 11:59:14.209962000 +0000
+++ solo/solotool.py
@@ -32,8 +32,8 @@ from cryptography.hazmat.primitives impo
 from fido2.attestation import Attestation
 from fido2.client import ClientError, Fido2Client
 from fido2.ctap import CtapError
-from fido2.ctap1 import CTAP1, ApduError
-from fido2.ctap2 import CTAP2
+from fido2.ctap1 import Ctap1, ApduError
+from fido2.ctap2 import Ctap2
 from fido2.hid import CTAPHID, CtapHidDevice
 from intelhex import IntelHex
 
