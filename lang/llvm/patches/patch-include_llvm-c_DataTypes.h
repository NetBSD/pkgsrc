$NetBSD: patch-include_llvm-c_DataTypes.h,v 1.1 2018/12/15 23:41:45 jperkin Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- include/llvm-c/DataTypes.h.orig	2018-04-02 13:22:26.000000000 +0000
+++ include/llvm-c/DataTypes.h
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
