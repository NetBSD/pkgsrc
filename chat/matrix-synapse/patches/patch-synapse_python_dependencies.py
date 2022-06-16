$NetBSD: patch-synapse_python_dependencies.py,v 1.10 2022/06/16 00:29:04 gdt Exp $

Patch out cryptography check: It doesn't need a version this high and it was
added by upstream as an ugly hack to force a patched OpenSSL, in case it is
linked statically.

--- synapse/python_dependencies.py.orig	2022-04-19 10:29:51.000000000 +0000
+++ synapse/python_dependencies.py
@@ -80,9 +80,6 @@ REQUIREMENTS = [
     "bleach>=1.4.3",
     # We use `ParamSpec`, which was added in `typing-extensions` 3.10.0.0.
     "typing-extensions>=3.10.0",
-    # We enforce that we have a `cryptography` version that bundles an `openssl`
-    # with the latest security patches.
-    "cryptography>=3.4.7",
     # ijson 3.1.4 fixes a bug with "." in property names
     "ijson>=3.1.4",
     "matrix-common~=1.1.0",
