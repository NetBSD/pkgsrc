$NetBSD: patch-libstdc++-v3_src_c++11_cow-stdexcept.cc,v 1.1 2016/10/19 12:38:41 ryoon Exp $

--- libstdc++-v3/src/c++11/cow-stdexcept.cc.orig	2016-05-11 19:06:45.000000000 +0000
+++ libstdc++-v3/src/c++11/cow-stdexcept.cc
@@ -271,9 +271,11 @@ _txnal_cow_string_C1_for_exceptions(void
 
 static void* txnal_read_ptr(void* const * ptr)
 {
+#if 0
   static_assert(sizeof(uint64_t) == sizeof(void*)
 		|| sizeof(uint32_t) == sizeof(void*),
 		"Pointers must be 32 bits or 64 bits wide");
+#endif
 #if __UINTPTR_MAX__ == __UINT64_MAX__
   return (void*)_ITM_RU8((const uint64_t*)ptr);
 #else
