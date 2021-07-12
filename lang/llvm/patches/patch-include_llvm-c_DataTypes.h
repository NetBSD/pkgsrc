$NetBSD: patch-include_llvm-c_DataTypes.h,v 1.2 2021/07/12 18:41:02 adam Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- include/llvm-c/DataTypes.h.orig	2021-04-06 16:38:18.000000000 +0000
+++ include/llvm-c/DataTypes.h
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
