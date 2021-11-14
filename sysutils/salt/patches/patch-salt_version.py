$NetBSD: patch-salt_version.py,v 1.2 2021/11/14 20:01:17 adam Exp $

Correctly detect py-cryptodome (the drop-in replacement for py-crypto).

--- salt/version.py.orig	2021-10-12 15:43:35.000000000 +0000
+++ salt/version.py
@@ -699,7 +699,7 @@ def dependency_information(include_salt_
         ("msgpack", "msgpack", "version"),
         ("msgpack-pure", "msgpack_pure", "version"),
         ("pycrypto", "Crypto", "__version__"),
-        ("pycryptodome", "Cryptodome", "version_info"),
+        ("pycryptodome", "Crypto", "version_info"),
         ("PyYAML", "yaml", "__version__"),
         ("PyZMQ", "zmq", "__version__"),
         ("ZMQ", "zmq", "zmq_version"),
