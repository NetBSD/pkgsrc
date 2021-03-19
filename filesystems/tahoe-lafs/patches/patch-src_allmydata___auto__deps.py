$NetBSD: patch-src_allmydata___auto__deps.py,v 1.1 2021/03/19 14:30:23 gdt Exp $

Adjust dependency from crypto to cryptodome

--- src/allmydata/_auto_deps.py.orig	2017-01-19 00:58:01.000000000 +0000
+++ src/allmydata/_auto_deps.py
@@ -48,7 +48,7 @@ install_requires = [
     # Needed for SFTP.
     # pycrypto 2.2 doesn't work due to <https://bugs.launchpad.net/pycrypto/+bug/620253>
     # pycrypto 2.4 doesn't work due to <https://bugs.launchpad.net/pycrypto/+bug/881130>
-    "pycrypto >= 2.1.0, != 2.2, != 2.4",
+    "pycryptodome >= 3.10.1",
 
     # pycryptopp-0.6.0 includes ed25519
     "pycryptopp >= 0.6.0",
