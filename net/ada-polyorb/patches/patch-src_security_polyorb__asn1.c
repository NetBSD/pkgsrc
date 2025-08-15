$NetBSD: patch-src_security_polyorb__asn1.c,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix incorrect casts

--- src/security/polyorb_asn1.c.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/security/polyorb_asn1.c
@@ -94,7 +94,7 @@
 
 ASN1_OBJECT *__PolyORB_ASN1_OBJECT_dup(ASN1_OBJECT *x) {
     return (ASN1_OBJECT *)ASN1_dup
-        ((int (*)())i2d_ASN1_OBJECT,
-        (void * (*)(void **, const unsigned char **, long int))d2i_ASN1_OBJECT,
-        (char *)x);
+        ((i2d_of_void *)i2d_ASN1_OBJECT,
+        (d2i_of_void *)d2i_ASN1_OBJECT,
+        (const void *)x);
 }
