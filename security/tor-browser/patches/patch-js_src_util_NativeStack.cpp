$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.1 2019/02/25 15:32:24 wiz Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2019-02-23 20:00:48.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -40,7 +40,7 @@ void* js::GetNativeStackBaseImpl() {
   return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 JS_STATIC_ASSERT(JS_STACK_GROWTH_DIRECTION < 0);
 
@@ -86,6 +86,7 @@ void* js::GetNativeStackBaseImpl() {
     return stackBase;
   }
 
+#  elif defined(__sun)
   // Non-main threads have the required info stored in memory, so no filesystem
   // calls are made.
   pthread_t thread = pthread_self();
