$NetBSD: patch-mozilla_certdata2pem.py,v 1.1 2022/07/17 02:58:32 tnn Exp $

py-cryptography fallout:
TypeError: argument 'data': 'bytearray' object cannot be converted to 'PyBytes'

--- mozilla/certdata2pem.py.orig	2021-10-16 16:09:43.000000000 +0000
+++ mozilla/certdata2pem.py
@@ -122,7 +122,7 @@ for obj in objects:
         if not obj['CKA_LABEL'] in trust or not trust[obj['CKA_LABEL']]:
             continue
 
-        cert = x509.load_der_x509_certificate(obj['CKA_VALUE'])
+        cert = x509.load_der_x509_certificate(bytes(obj['CKA_VALUE']))
         if cert.not_valid_after < datetime.datetime.now():
             print('!'*74)
             print('Trusted but expired certificate found: %s' % obj['CKA_LABEL'])
