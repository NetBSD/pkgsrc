$NetBSD: patch-setup.py,v 1.1 2017/01/01 21:50:31 schmonz Exp $

Allow installation with multiple Python versions.

--- setup.py.orig	2014-11-13 02:22:47.000000000 +0000
+++ setup.py
@@ -12,5 +12,5 @@ setup(name="tlslite",
       url="http://trevp.net/tlslite/",
       description="tlslite implements SSL and TLS.",
       license="public domain and BSD",
-      scripts=["scripts/tls.py", "scripts/tlsdb.py"],
+      scripts=["scripts/tls@PYVERSSUFFIX@.py", "scripts/tlsdb@PYVERSSUFFIX@.py"],
       packages=["tlslite", "tlslite.utils", "tlslite.integration"],)
