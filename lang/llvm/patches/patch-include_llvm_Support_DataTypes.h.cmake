$NetBSD: patch-include_llvm_Support_DataTypes.h.cmake,v 1.1 2018/01/08 10:48:34 jperkin Exp $

Implement sys/regset.h workaround directly.

--- include/llvm/Support/DataTypes.h.cmake.orig	2017-06-06 11:49:48.000000000 +0000
+++ include/llvm/Support/DataTypes.h.cmake
@@ -132,4 +132,32 @@ typedef signed int ssize_t;
 #define HUGE_VALF (float)HUGE_VAL
 #endif
 
+/*
+ * At some point sys/regset.h will be included, and on older releases
+ * of illumos it exports conflicting macros used by LLVM.  Include it
+ * early and ensure they are undefined first.
+ */
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
