$NetBSD: patch-src_gc.cpp,v 1.1 2014/04/17 06:20:27 wiz Exp $

    Committer: Johan B. C. Engelen
    Date: 2014-01-12 21:00:46 UTC
    Revision ID: j.b.c.engelen@alumnus.utwente.nl-20140112210046-w4k02e3v5wkwg2za

https://launchpad.net/bugs/1265072
fix build with boehm-gc 7.4.0+ (patch by Vladimir Smirnov, slightly modified by me)


--- src/gc.cpp.orig	2012-02-14 03:22:17.000000000 +0000
+++ src/gc.cpp
@@ -70,9 +70,13 @@ void *debug_base(void *ptr) {
     return base + debug_base_fixup();
 }
 
-int debug_general_register_disappearing_link(void **p_ptr, void *base) {
-    char *real_base=reinterpret_cast<char *>(base) - debug_base_fixup();
+int debug_general_register_disappearing_link(void **p_ptr, void const *base) {
+    char const *real_base = reinterpret_cast<char const *>(base) - debug_base_fixup();
+#if (GC_MAJOR_VERSION >= 7 && GC_MINOR_VERSION >= 4)
     return GC_general_register_disappearing_link(p_ptr, real_base);
+#else // compatibility with older Boehm GC versions
+    return GC_general_register_disappearing_link(p_ptr, const_cast<char *>(real_base));
+#endif
 }
 
 void dummy_do_init() {}
@@ -90,7 +94,7 @@ void dummy_register_finalizer(void *, Cl
     }
 }
 
-int dummy_general_register_disappearing_link(void **, void *) { return false; }
+int dummy_general_register_disappearing_link(void **, void const *) { return false; }
 
 int dummy_unregister_disappearing_link(void **/*link*/) { return false; }
 
@@ -112,7 +116,11 @@ Ops enabled_ops = {
     &GC_malloc_atomic_uncollectable,
     &GC_base,
     &GC_register_finalizer_ignore_self,
-    &GC_general_register_disappearing_link,
+#if (GC_MAJOR_VERSION >= 7 && GC_MINOR_VERSION >= 4)
+     &GC_general_register_disappearing_link,
+#else // compatibility with older Boehm GC versions
+    (int (*)(void**, const void*))(&GC_general_register_disappearing_link),
+#endif
     &GC_unregister_disappearing_link,
     &GC_get_heap_size,
     &GC_get_free_bytes,
@@ -202,7 +210,7 @@ void stub_register_finalizer_ignore_self
     die_because_not_initialized();
 }
 
-int stub_general_register_disappearing_link(void **, void *) {
+int stub_general_register_disappearing_link(void **, void const *) {
     die_because_not_initialized();
     return 0;
 }
