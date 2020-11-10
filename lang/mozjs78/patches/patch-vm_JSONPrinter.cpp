$NetBSD: patch-vm_JSONPrinter.cpp,v 1.1 2020/11/10 11:27:10 nia Exp $

For NetBSD/arm, size_t is unsigned long, which is neither
uint32_t (= unsigned int) nor uint64_t (= unsigned long long).

--- vm/JSONPrinter.cpp.orig	2020-09-25 09:22:59.000000000 +0000
+++ vm/JSONPrinter.cpp
@@ -146,7 +146,8 @@ void JSONPrinter::property(const char* n
   out_.printf("%" PRIu64, value);
 }
 
-#if defined(XP_DARWIN) || defined(__OpenBSD__)
+#if defined(XP_DARWIN) || defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && defined(__arm__))
 void JSONPrinter::property(const char* name, size_t value) {
   propertyName(name);
   out_.printf("%zu", value);
