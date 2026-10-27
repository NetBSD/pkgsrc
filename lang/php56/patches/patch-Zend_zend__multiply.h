$NetBSD: patch-Zend_zend__multiply.h,v 1.2 2026/10/27 15:30:49 taca Exp $

https://mail-index.netbsd.org/pkgsrc-users/2026/08/28/msg043351.html
Quick hack by importing from php85 

--- Zend/zend_multiply.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_multiply.h
@@ -57,13 +57,16 @@
 
 #elif defined(__aarch64__) && defined(__GNUC__)
 
+typedef int64_t zend_long;
+
+
 #define ZEND_SIGNED_MULTIPLY_LONG(a, b, lval, dval, usedval) do {	\
-	long __tmpvar; 													\
+	zend_long __tmpvar; 													\
 	__asm__("mul %0, %2, %3\n"										\
 		"smulh %1, %2, %3\n"										\
 		"sub %1, %1, %0, asr #63\n"									\
-			: "=X"(__tmpvar), "=X"(usedval)							\
-			: "X"(a), "X"(b));										\
+                       : "=&r"(__tmpvar), "=&r"(usedval)                      \
+                       : "r"(a), "r"(b));                                     \
 	if (usedval) (dval) = (double) (a) * (double) (b);				\
 	else (lval) = __tmpvar;											\
 } while (0)
