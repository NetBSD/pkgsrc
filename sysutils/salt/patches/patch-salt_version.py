$NetBSD: patch-salt_version.py,v 1.1 2018/02/07 11:11:23 adam Exp $

Correctly detect py-cryptodome (the drop-in replacement for py-crypto).

--- salt/version.py.orig	2018-02-07 10:27:26.000000000 +0000
+++ salt/version.py
@@ -581,7 +581,7 @@ def dependency_information(include_salt_
         ('msgpack-python', 'msgpack', 'version'),
         ('msgpack-pure', 'msgpack_pure', 'version'),
         ('pycrypto', 'Crypto', '__version__'),
-        ('pycryptodome', 'Cryptodome', 'version_info'),
+        ('pycryptodome', 'Crypto', 'version_info'),
         ('libnacl', 'libnacl', '__version__'),
         ('PyYAML', 'yaml', '__version__'),
         ('ioflo', 'ioflo', '__version__'),
