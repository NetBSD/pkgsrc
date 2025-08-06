$NetBSD: patch-src_hotspot_cpu_aarch64_jniFastGetField__aarch64.cpp,v 1.1 2025/08/06 08:47:15 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp.orig	2025-04-19 18:17:03.000000000 +0000
+++ src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp
@@ -32,6 +32,7 @@
 #include "prims/jvm_misc.hpp"
 #include "prims/jvmtiExport.hpp"
 #include "runtime/safepoint.hpp"
+#include "runtime/thread.inline.hpp"
 #include "runtime/threadWXSetters.inline.hpp"
 
 #define __ masm->
@@ -58,8 +59,6 @@ static const Register result        = r7
 // (8262896).  So each FastGetXXXField is wrapped into a C++ statically
 // compiled template function that optionally switches to WXExec if necessary.
 
-#ifdef __APPLE__
-
 static address generated_fast_get_field[T_LONG + 1 - T_BOOLEAN];
 
 template<int BType> struct BasicTypeToJni {};
@@ -86,15 +85,6 @@ address JNI_FastGetField::generate_fast_
   return (address)static_fast_get_field_wrapper<BType>;
 }
 
-#else // __APPLE__
-
-template<int BType>
-address JNI_FastGetField::generate_fast_get_int_field1() {
-  return generate_fast_get_int_field0((BasicType)BType);
-}
-
-#endif // __APPLE__
-
 address JNI_FastGetField::generate_fast_get_int_field0(BasicType type) {
   const char *name;
   switch (type) {
