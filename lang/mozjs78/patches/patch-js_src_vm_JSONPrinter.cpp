$NetBSD: patch-js_src_vm_JSONPrinter.cpp,v 1.1 2020/12/05 12:03:26 nia Exp $

For NetBSD/arm, size_t is unsigned long, which is neither
uint32_t (= unsigned int) nor uint64_t (= unsigned long long).

--- js/src/vm/JSONPrinter.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/vm/JSONPrinter.cpp
@@ -146,7 +146,8 @@ void JSONPrinter::property(const char* n
   out_.printf("%" PRIu64, value);
 }
 
-#if defined(XP_DARWIN) || defined(__OpenBSD__)
+#if defined(XP_DARWIN) || defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && defined(__arm__))
 void JSONPrinter::property(const char* name, size_t value) {
   propertyName(name);
   out_.printf("%zu", value);
