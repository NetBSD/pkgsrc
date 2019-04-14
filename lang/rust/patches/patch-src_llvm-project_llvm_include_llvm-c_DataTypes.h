$NetBSD: patch-src_llvm-project_llvm_include_llvm-c_DataTypes.h,v 1.1 2019/04/14 12:42:03 he Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- src/llvm-project/llvm/include/llvm-c/DataTypes.h.orig	2018-08-01 16:32:37.000000000 +0000
+++ src/llvm-project/llvm/include/llvm-c/DataTypes.h
@@ -87,4 +87,27 @@ typedef signed int ssize_t;
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
 #endif /* LLVM_C_DATATYPES_H */
