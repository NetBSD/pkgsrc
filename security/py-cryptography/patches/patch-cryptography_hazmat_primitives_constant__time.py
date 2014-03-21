$NetBSD: patch-cryptography_hazmat_primitives_constant__time.py,v 1.1 2014/03/21 14:02:45 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/primitives/constant_time.py.orig	2014-03-04 00:51:26.000000000 +0000
+++ cryptography/hazmat/primitives/constant_time.py
@@ -45,6 +45,7 @@ uint8_t Cryptography_constant_time_bytes
 }
 """,
     ext_package="cryptography",
+    modulename="constanttime",
 )
 
 
