$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.10 2014/10/30 16:45:39 ryoon Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2014-09-16 20:10:41.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -31,6 +31,25 @@
 #include "config_gcc.h"
 #include "uno/mapping.h"
 
+#ifdef _LIBCPP_VERSION
+
+namespace __cxxabiv1
+{
+    struct __class_type_info : public std::type_info
+    {
+        explicit __class_type_info( const char *__n ) : type_info( __n ) { }
+        virtual ~__class_type_info();
+    };
+
+    struct __si_class_type_info : public __class_type_info
+    {
+        explicit __si_class_type_info( const char *__n, const __class_type_info *__b ) :
+            __class_type_info( __n ), __base_type( __b ) { }
+        virtual ~__si_class_type_info();
+        const __class_type_info *__base_type;
+    };
+}
+#else
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -72,6 +91,7 @@ struct __cxa_eh_globals
 };
 
 }
+#endif
 
 // __cxa_get_globals is exported from libstdc++ since GCC 3.4.0 (CXXABI_1.3),
 // but it is only declared in cxxabi.h (in namespace __cxxabiv1) since
@@ -109,7 +129,11 @@ void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 
 void fillUnoException(
+#if _LIBCPP_VERSION
+    __cxxabiv1::__cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#else
     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#endif
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
