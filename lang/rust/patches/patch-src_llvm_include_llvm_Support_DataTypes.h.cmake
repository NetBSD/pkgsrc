$NetBSD: patch-src_llvm_include_llvm_Support_DataTypes.h.cmake,v 1.1 2018/06/21 17:13:13 jperkin Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- src/llvm/include/llvm/Support/DataTypes.h.cmake.orig	2018-03-10 02:51:13.000000000 +0000
+++ src/llvm/include/llvm/Support/DataTypes.h.cmake
@@ -132,4 +132,27 @@ typedef signed int ssize_t;
 #define HUGE_VALF (float)HUGE_VAL
 #endif
 
+#if defined(__sun)
+#include <sys/regset.h>
+#undef CS
+#undef DS
+#undef ES
+#undef FS
+#undef GS
+#undef SS
+#undef EAX
+#undef ECX
+#undef EDX
+#undef EBX
+#undef ESP
+#undef EBP
+#undef ESI
+#undef EDI
+#undef EIP
+#undef UESP
+#undef EFL
+#undef ERR
+#undef TRAPNO
+#endif
+
 #endif /* SUPPORT_DATATYPES_H */
