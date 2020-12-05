$NetBSD: patch-js_src_vm_JSONPrinter.h,v 1.1 2020/12/05 12:03:26 nia Exp $

For NetBSD/arm, size_t is unsigned long, which is neither
uint32_t (= unsigned int) nor uint64_t (= unsigned long long).

--- js/src/vm/JSONPrinter.h.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/vm/JSONPrinter.h
@@ -51,7 +51,8 @@ class JSONPrinter {
   void property(const char* name, uint32_t value);
   void property(const char* name, int64_t value);
   void property(const char* name, uint64_t value);
-#if defined(XP_DARWIN) || defined(__OpenBSD__)
+#if defined(XP_DARWIN) || defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && defined(__arm__))
   // On OSX and OpenBSD, size_t is long unsigned, uint32_t is unsigned, and
   // uint64_t is long long unsigned. Everywhere else, size_t matches either
   // uint32_t or uint64_t.
