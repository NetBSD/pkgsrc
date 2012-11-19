$NetBSD: patch-src_qibusserializable.h,v 1.1 2012/11/19 23:21:39 joerg Exp $

--- src/qibusserializable.h.orig	2012-11-19 16:45:31.000000000 +0000
+++ src/qibusserializable.h
@@ -91,7 +91,7 @@ private:
 
 template<typename T>
 QVariant &
-qVariantFromSerializable (const Pointer<T> &p, QVariant & variant = QVariant ())
+qVariantFromSerializable (const Pointer<T> &p, QVariant & variant)
 {
     QDBusArgument argument;
 
