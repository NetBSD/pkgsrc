$NetBSD: patch-paramiko_ssh__gss.py,v 1.1 2018/03/29 15:35:32 adam Exp $

Paramiko does not work with current py-gssapi.
https://github.com/paramiko/paramiko/issues/1069

--- paramiko/ssh_gss.py.orig	2017-10-30 11:10:54.000000000 +0000
+++ paramiko/ssh_gss.py
@@ -50,7 +50,7 @@ from pyasn1.codec.der import encoder, de
 _API = "MIT"
 
 try:
-    import gssapi
+    import gssapi_fails
     GSS_EXCEPTIONS = (gssapi.GSSException,)
 except (ImportError, OSError):
     try:
