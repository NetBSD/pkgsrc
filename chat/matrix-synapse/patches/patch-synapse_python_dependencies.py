$NetBSD: patch-synapse_python_dependencies.py,v 1.7 2022/03/18 12:23:50 gdt Exp $

Patch out cryptography check: It doesn't need a version this high and it was
added by upstream as an ugly hack to force a patched OpenSSL, in case it is
linked statically.

--- synapse/python_dependencies.py.orig	2022-03-08 14:01:19.000000000 +0000
+++ synapse/python_dependencies.py
@@ -77,9 +77,6 @@ REQUIREMENTS = [
     "Jinja2>=2.9",
     "bleach>=1.4.3",
     "typing-extensions>=3.7.4",
-    # We enforce that we have a `cryptography` version that bundles an `openssl`
-    # with the latest security patches.
-    "cryptography>=3.4.7",
     # ijson 3.1.4 fixes a bug with "." in property names
     "ijson>=3.1.4",
     "matrix-common~=1.1.0",
