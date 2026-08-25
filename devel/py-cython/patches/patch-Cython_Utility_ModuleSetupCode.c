$NetBSD: patch-Cython_Utility_ModuleSetupCode.c,v 1.1 2026/08/25 10:50:00 wiz Exp $

Use std::isfinite() is C++ and isfinite() in C.
https://github.com/cython/cython/pull/7930

--- Cython/Utility/ModuleSetupCode.c.orig	2026-08-22 04:59:36.771782400 +0000
+++ Cython/Utility/ModuleSetupCode.c
@@ -1643,6 +1643,14 @@ static CYTHON_INLINE int __Pyx_IsAnySubtype2(PyTypeObj
 #define __Pyx_truncl truncl
 #endif
 
+#if defined(__cplusplus)
+  #include <cmath>
+  #define __Pyx_isfinite(x)  std::isfinite(x)
+#else
+  #define __Pyx_isfinite(x)  isfinite(x)
+#endif
+
+
 /////////////// ForceInitThreads.proto ///////////////
 //@proto_block: utility_code_proto_before_types
 
