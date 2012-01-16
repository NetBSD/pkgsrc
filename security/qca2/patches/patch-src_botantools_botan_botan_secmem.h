$NetBSD: patch-src_botantools_botan_botan_secmem.h,v 1.1 2012/01/16 20:36:08 adam Exp $

--- src/botantools/botan/botan/secmem.h.orig	2012-01-16 18:21:07.000000000 +0000
+++ src/botantools/botan/botan/secmem.h
@@ -214,7 +214,7 @@ class SecureVector : public MemoryRegion
 
       SecureVector(u32bit n = 0) { MemoryRegion<T>::init(true, n); }
       SecureVector(const T in[], u32bit n)
-         { MemoryRegion<T>::init(true); set(in, n); }
+         { MemoryRegion<T>::init(true); this->set(in, n); }
       SecureVector(const MemoryRegion<T>& in)
          { MemoryRegion<T>::init(true); set(in); }
       SecureVector(const MemoryRegion<T>& in1, const MemoryRegion<T>& in2)
