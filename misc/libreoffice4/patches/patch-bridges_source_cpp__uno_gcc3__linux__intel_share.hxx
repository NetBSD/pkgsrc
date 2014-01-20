$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_share.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_intel/share.hxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/share.hxx
@@ -69,7 +69,33 @@ struct __cxa_eh_globals
 
 }
 
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
 extern "C" CPPU_CURRENT_NAMESPACE::__cxa_eh_globals *__cxa_get_globals () throw();
+#endif
 
 namespace CPPU_CURRENT_NAMESPACE
 {
