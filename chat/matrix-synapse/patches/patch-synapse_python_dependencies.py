$NetBSD: patch-synapse_python_dependencies.py,v 1.5 2022/01/30 11:17:10 wiz Exp $

Patch out cryptography check: It doesn't need a version this high and it was
added by upstream as an ugly hack to force a patched OpenSSL, in case it is
linked statically.

Relax other restrictions since pkgsrc has/will have newer versions.

--- synapse/python_dependencies.py.orig	2022-01-25 11:42:32.000000000 +0000
+++ synapse/python_dependencies.py
@@ -51,7 +51,7 @@ REQUIREMENTS = [
     # we use the TYPE_CHECKER.redefine method added in jsonschema 3.0.0
     "jsonschema>=3.0.0",
     # frozendict 2.1.2 is broken on Debian 10: https://github.com/Marco-Sulla/python-frozendict/issues/41
-    "frozendict>=1,<2.1.2",
+    "frozendict>=1",
     "unpaddedbase64>=1.1.0",
     "canonicaljson>=1.4.0",
     # we use the type definitions added in signedjson 1.1.
@@ -84,11 +84,8 @@ REQUIREMENTS = [
     "Jinja2>=2.9",
     "bleach>=1.4.3",
     "typing-extensions>=3.7.4",
-    # We enforce that we have a `cryptography` version that bundles an `openssl`
-    # with the latest security patches.
-    "cryptography>=3.4.7",
     "ijson>=3.1",
-    "matrix-common==1.0.0",
+    "matrix-common",
 ]
 
 CONDITIONAL_REQUIREMENTS = {
