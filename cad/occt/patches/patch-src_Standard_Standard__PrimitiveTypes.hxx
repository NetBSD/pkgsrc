$NetBSD: patch-src_Standard_Standard__PrimitiveTypes.hxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

From cad/oce:
Undefine SunOS registers that are forcibly pulled in by headers,
and clash with some OpenCASCADE variables.
v 1.1 2017/01/20 11:00:50 fhajny

--- src/Standard/Standard_PrimitiveTypes.hxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/Standard/Standard_PrimitiveTypes.hxx
@@ -18,6 +18,28 @@
 #include <stddef.h>
 #include <stdlib.h>
 
+#if defined(__sun)
+#undef CS
+#undef DS
+#undef ES
+#undef FS
+#undef GS
+#undef SS
+#undef EAX
+#undef EBP
+#undef EBX
+#undef ECX
+#undef EDI
+#undef EEDX
+#undef EFL
+#undef EIP
+#undef ERR
+#undef ESI
+#undef ESP
+#undef TRAPNO
+#undef UESP
+#endif
+
 #include <Standard_Macro.hxx>
 
 #include <Standard_Boolean.hxx>
