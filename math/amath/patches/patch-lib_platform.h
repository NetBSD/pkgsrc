$NetBSD: patch-lib_platform.h,v 1.1 2017/02/17 17:09:17 joerg Exp $

Replace operators must be global.

--- lib/platform.h.orig	2017-02-17 12:09:25.174210005 +0000
+++ lib/platform.h
@@ -138,21 +138,10 @@ typedef u_int32_t   uint32_t;
 typedef u_int64_t   uint64_t;
 # define IPTR LONG*
 #ifdef __cplusplus
-inline void* operator new (size_t size) {
-    return AllocMemSafe(size);
-}
-
-inline void* operator new[] (size_t size) {
-    return AllocMemSafe(size);
-}
-
-inline void  operator delete (void* ptr) {
-    FreeMemSafe(ptr);
-}
-
-inline void  operator delete[] (void* ptr) {
-    FreeMemSafe(ptr);
-}
+void* operator new (size_t size);
+void* operator new[] (size_t size);
+void  operator delete (void* ptr);
+void  operator delete[] (void* ptr);
 #endif
 #endif
 
@@ -164,21 +153,10 @@ inline void  operator delete[] (void* pt
 #ifdef __cplusplus
 #if (__GNUC__ > 2) || defined (_WIN32)
 #include <new>
-inline void* operator new (size_t size) throw(std::bad_alloc) {
-    return AllocMemSafe(size);
-}
-
-inline void* operator new[] (size_t size) throw(std::bad_alloc) {
-    return AllocMemSafe(size);
-}
-
-inline void  operator delete (void* ptr) throw() {
-    FreeMemSafe(ptr);
-}
-
-inline void  operator delete[] (void* ptr) throw() {
-    FreeMemSafe(ptr);
-}
+void* operator new (size_t size) throw(std::bad_alloc);
+void* operator new[] (size_t size) throw(std::bad_alloc);
+void  operator delete (void* ptr) throw();
+void  operator delete[] (void* ptr) throw();
 #endif
 #endif
 
