$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.3 2016/02/12 19:34:29 tnn Exp $

Deal with more non-standard introspection requirements from cxxabi.h. (fixes build w/ clang)

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2015-08-13 17:21:26.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -40,6 +40,14 @@ namespace __cxxabiv1
     {
         explicit __class_type_info( const char *__n ) : type_info( __n ) { }
         virtual ~__class_type_info();
+
+        enum __offset_flags_masks
+        {
+            __virtual_mask = 0x1,
+            __public_mask = 0x2,
+            __hwm_bit = 2,
+            __offset_shift = 8
+        };
     };
 
     struct __si_class_type_info : public __class_type_info
@@ -50,6 +58,34 @@ namespace __cxxabiv1
         const __class_type_info *__base_type;
     };
 
+    struct __base_class_type_info {
+        const __class_type_info *__base_type;
+        uintptr_t __offset_flags;
+
+        enum __offset_flags_masks {
+            __virtual_mask = 0x1,
+            __public_mask = 0x2,
+            __hwm_bit = 2,
+            __offset_shift = 8
+        };
+    };
+
+    struct __vmi_class_type_info : public __class_type_info {
+        unsigned int __flags;
+        unsigned int __base_count;
+        __base_class_type_info __base_info[0];
+
+        explicit __vmi_class_type_info(const char *__n, int ___flags) :
+          __class_type_info(__n), __flags(___flags), __base_count(0) {}
+
+        enum __flags_masks
+        {
+            __non_diamond_repeat_mask = 0x1,
+            __diamond_shaped_mask = 0x2,
+            __flags_unknown_mask = 0x10
+        };
+    };
+
 extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
 
 extern "C" _LIBCPP_NORETURN void __cxa_throw(
