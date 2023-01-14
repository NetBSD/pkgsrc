$NetBSD: patch-objcxx_eh.cc,v 1.3 2023/01/14 01:30:53 manu Exp $

Workaround build failure due to redefinition and include correct header.

--- ./objcxx_eh.cc.orig	2020-08-23 15:10:20.000000000 +0000
+++ ./objcxx_eh.cc	2023-01-11 13:01:46.256573178 +0000
@@ -5,8 +5,9 @@
 #include "dwarf_eh.h"
 #include "objcxx_eh.h"
 #include "visibility.h"
 #include "objc/runtime.h"
+#include <typeinfo>
 
 /**
  * Helper function that has a custom personality function.
  * This calls `cxx_throw` and has a destructor that must be run.  We intercept
@@ -56,8 +57,9 @@
 	 */
 	extern "C" __cxa_eh_globals *__cxa_get_globals();
 }
 
+#if 0
 namespace std
 {
 	struct type_info;
 }
@@ -99,8 +101,9 @@
 				public:
 				const char* name() const { return __type_name; }
 	};
 }
+#endif
 
 namespace
 {
 /**
@@ -190,9 +193,9 @@
 	// __cxa_exception takes a pointer to the end of the __cxa_exception
 	// structure, and so we find that by adding the size of the generic
 	// exception structure + padding to the pointer to the generic exception
 	// structure field of the enclosing structure.
-	auto *cxxEx = pointer_add<__cxa_exception>(ex, exception_struct_size);
+	auto *cxxEx = pointer_add<__cxxabiv1::__cxa_exception>(ex, exception_struct_size);
 	__cxa_free_exception(cxxEx);
 }
 
 }
@@ -262,9 +265,9 @@
 			 *
 			 * This should never be called on Objective-C types.
 			 */
 			virtual bool __do_upcast(
-			                const __class_type_info *target,
+			                const __cxxabiv1::__class_type_info *target,
 			                void **thrown_object) const
 			{
 				return false;
 			};
@@ -374,9 +377,9 @@
 	_Unwind_Exception *ex = pointer_add<_Unwind_Exception>(newEx, -exception_struct_size);
 	*pointer_add<std::type_info*>(ex, type_info_offset) = &__objc_id_type_info;
 	ex->exception_class = cxx_exception_class;
 	ex->exception_cleanup = exception_cleanup;
-	__cxa_get_globals()->uncaughtExceptions++;
+	__cxxabiv1::__cxa_get_globals()->uncaughtExceptions++;
 	return ex;
 }
 
 void* objc_object_for_cxx_exception(void *thrown_exception, int *isValid)
