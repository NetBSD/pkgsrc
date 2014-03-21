$NetBSD: patch-cryptography_hazmat_primitives_padding.py,v 1.1 2014/03/21 14:02:45 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/primitives/padding.py.orig	2014-03-04 00:51:26.000000000 +0000
+++ cryptography/hazmat/primitives/padding.py
@@ -62,6 +62,7 @@ uint8_t Cryptography_check_pkcs7_padding
 }
 """,
     ext_package="cryptography",
+    modulename="checkpkcs7padding",
 )
 
 
