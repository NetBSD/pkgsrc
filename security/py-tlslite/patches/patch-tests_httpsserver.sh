$NetBSD: patch-tests_httpsserver.sh,v 1.1 2017/01/01 21:50:31 schmonz Exp $

Use the intended Python interpreter.

--- tests/httpsserver.sh.orig	2014-11-13 02:22:47.000000000 +0000
+++ tests/httpsserver.sh
@@ -1,2 +1,2 @@
 # /bin/sh
-python ../scripts/tls.py server -k serverX509Key.pem -c serverX509Cert.pem -t TACK1.pem localhost:4443
+@PYTHONBIN@ ../scripts/tls@PYVERSSUFFIX@.py server -k serverX509Key.pem -c serverX509Cert.pem -t TACK1.pem localhost:4443
