$NetBSD: patch-deps_v8_src_zone_zone.h,v 1.1 2022/03/30 06:51:31 adam Exp $

Work around type issue in NetBSD's copy of libc++ headers.
Believed to be fixed in upstream libc++ already.
https://github.com/nodejs/node/issues/30638

--- deps/v8/src/zone/zone.h.orig	2019-12-18 17:26:45.000000000 +0000
+++ deps/v8/src/zone/zone.h
@@ -141,6 +141,9 @@ class ZoneObject {
  public:
   // Allocate a new ZoneObject of 'size' bytes in the Zone.
   void* operator new(size_t size, Zone* zone) { return zone->New(size); }
+#if defined(__NetBSD__) && defined(__clang__)
+  void* operator new(size_t size, void* zone) { return ((Zone*)zone)->New(size); }
+#endif
 
   // Ideally, the delete operator should be private instead of
   // public, but unfortunately the compiler sometimes synthesizes
