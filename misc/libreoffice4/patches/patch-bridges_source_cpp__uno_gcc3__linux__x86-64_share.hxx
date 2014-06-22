$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.5 2014/06/22 23:59:36 ryoon Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -31,6 +31,32 @@
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
+
+extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
+
+extern "C" _LIBCPP_NORETURN void __cxa_throw(
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) );
+}
+
+#else
+
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -102,6 +128,9 @@ extern "C" void __cxa_throw(
 }
 #endif
 
+
+#endif
+
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -110,7 +139,11 @@ void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 //==================================================================================================
 void fillUnoException(
+#ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#else
     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#endif
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
