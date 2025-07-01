$NetBSD: patch-salt_version.py,v 1.3 2025/07/01 13:41:40 adam Exp $

Correctly detect py-cryptodome (the drop-in replacement for py-crypto).

--- salt/version.py.orig	2025-06-26 18:26:26.000000000 +0000
+++ salt/version.py
@@ -707,7 +707,7 @@ def dependency_information(include_salt_
         ("msgpack", "msgpack", "version"),
         ("msgpack-pure", "msgpack_pure", "version"),
         ("pycrypto", "Crypto", "__version__"),
-        ("pycryptodome", "Cryptodome", "version_info"),
+        ("pycryptodome", "Crypto", "version_info"),
         ("cryptography", "cryptography", "__version__"),
         ("PyYAML", "yaml", "__version__"),
         ("PyZMQ", "zmq", "__version__"),
