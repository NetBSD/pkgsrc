$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.3 2019/05/22 14:24:43 wiz Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2019-02-23 20:00:48.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -40,7 +40,7 @@ void* js::GetNativeStackBaseImpl() {
   return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 JS_STATIC_ASSERT(JS_STACK_GROWTH_DIRECTION < 0);
 
@@ -128,6 +128,7 @@ void* js::GetNativeStackBaseImpl() {
 #elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
   /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
   pthread_attr_get_np(thread, &sattr);
+#elif defined(__sun)
 #else
   /*
    * FIXME: this function is non-portable;
