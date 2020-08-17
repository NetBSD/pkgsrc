$NetBSD: patch-ykman_driver__ccid.py,v 1.1 2020/08/17 07:02:25 riastradh Exp $

Avoid crashing if pcscd is missing.

--- ykman/driver_ccid.py.orig	2020-01-29 07:32:03.000000000 +0000
+++ ykman/driver_ccid.py
@@ -36,6 +36,7 @@ from enum import IntEnum, unique
 from binascii import b2a_hex
 from smartcard import System
 from smartcard.Exceptions import CardConnectionException
+from smartcard.pcsc.PCSCExceptions import EstablishContextException
 from smartcard.pcsc.PCSCExceptions import ListReadersException
 from smartcard.pcsc.PCSCContext import PCSCContext
 from .driver import AbstractDriver, ModeSwitchError, NotSupportedError
@@ -320,6 +321,8 @@ def list_readers():
         # removed):
         PCSCContext.instance = None
         return System.readers()
+    except EstablishContextException:
+        return []
 
 
 def open_devices(name_filter=YK_READER_NAME):
