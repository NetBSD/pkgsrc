$NetBSD: patch-synapse_python_dependencies.py,v 1.1 2021/04/28 23:44:56 js Exp $

Patch out cryptography check: It doesn't need a version this high and it was
added by upstream as an ugly hack to force a patched OpenSSL, in case it is
linked statically.

--- synapse/python_dependencies.py.orig	2021-04-22 10:09:31.000000000 +0000
+++ synapse/python_dependencies.py
@@ -83,9 +83,6 @@ REQUIREMENTS = [
     "Jinja2>=2.9",
     "bleach>=1.4.3",
     "typing-extensions>=3.7.4",
-    # We enforce that we have a `cryptography` version that bundles an `openssl`
-    # with the latest security patches.
-    "cryptography>=3.4.7;python_version>='3.6'",
 ]
 
 CONDITIONAL_REQUIREMENTS = {
