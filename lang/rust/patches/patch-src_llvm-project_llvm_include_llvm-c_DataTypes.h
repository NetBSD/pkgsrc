$NetBSD: patch-src_llvm-project_llvm_include_llvm-c_DataTypes.h,v 1.7 2023/10/25 05:50:43 pin Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- src/llvm-project/llvm/include/llvm-c/DataTypes.h.orig	2021-04-17 01:50:37.000000000 +0000
+++ src/llvm-project/llvm/include/llvm-c/DataTypes.h
@@ -77,4 +77,27 @@ typedef signed int ssize_t;
 # define UINT64_MAX 0xffffffffffffffffULL
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
