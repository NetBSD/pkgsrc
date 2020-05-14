$NetBSD: patch-vm_JSONPrinter.cpp,v 1.1 2020/05/14 08:44:48 rin Exp $

For NetBSD/arm, size_t is unsigned long, which is neither
uint32_t (= unsigned int) nor uint64_t (= unsigned long long).

--- vm/JSONPrinter.cpp.orig	2020-05-12 17:06:38.387691368 +0900
+++ vm/JSONPrinter.cpp	2020-05-12 17:10:20.842391283 +0900
@@ -119,7 +119,8 @@ void JSONPrinter::property(const char* n
   out_.printf("%" PRIu64, value);
 }
 
-#if defined(XP_DARWIN) || defined(__OpenBSD__)
+#if defined(XP_DARWIN) || defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && defined(__arm__))
 void JSONPrinter::property(const char* name, size_t value) {
   propertyName(name);
   out_.printf("%zu", value);
