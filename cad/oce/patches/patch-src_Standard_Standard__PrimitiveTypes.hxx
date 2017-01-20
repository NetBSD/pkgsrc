$NetBSD: patch-src_Standard_Standard__PrimitiveTypes.hxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

Undefine SunOS registers that are forcibly pulled in by headers,
and clash with some OpenCASCADE variables.

--- src/Standard/Standard_PrimitiveTypes.hxx.orig	2014-02-12 20:06:33.000000000 +0000
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
 class Standard_Type;
 class Handle_Standard_Type;
 
