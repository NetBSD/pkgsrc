$NetBSD: patch-paramiko_ssh__gss.py,v 1.2 2018/09/21 11:04:16 adam Exp $

Paramiko does not work with current py-gssapi.
https://github.com/paramiko/paramiko/issues/1069

--- paramiko/ssh_gss.py.orig	2018-09-19 04:21:52.000000000 +0000
+++ paramiko/ssh_gss.py
@@ -50,7 +50,7 @@ from pyasn1.codec.der import encoder, de
 _API = "MIT"
 
 try:
-    import gssapi
+    import gssapi_fails
 
     GSS_EXCEPTIONS = (gssapi.GSSException,)
 except (ImportError, OSError):
