$NetBSD: patch-src_core_alloc__func.hpp,v 1.1 2017/06/28 18:18:36 adam Exp $

Prefer built-in alloca() to avoid crashes.

--- src/core/alloc_func.hpp.orig	2017-06-26 13:04:45.346333800 +0000
+++ src/core/alloc_func.hpp
@@ -131,8 +131,14 @@ static inline T *ReallocT(T *t_ptr, size
 }
 
 /** alloca() has to be called in the parent function, so define AllocaM() as a macro */
+#ifdef __GNUC__
+#define AllocaM(T, num_elements) \
+	(CheckAllocationConstraints<T>(num_elements), \
+	(T*)__builtin_alloca((num_elements) * sizeof(T)))
+#else
 #define AllocaM(T, num_elements) \
 	(CheckAllocationConstraints<T>(num_elements), \
 	(T*)alloca((num_elements) * sizeof(T)))
+#endif
 
 #endif /* ALLOC_FUNC_HPP */
