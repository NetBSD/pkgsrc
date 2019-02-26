$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.2 2019/02/26 11:32:13 ryoon Exp $

--- js/src/util/NativeStack.cpp.orig	2019-02-13 14:19:39.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -30,7 +30,7 @@ void* js::GetNativeStackBaseImpl() {
   return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 #include <ucontext.h>
 
@@ -69,6 +69,7 @@ void* js::GetNativeStackBaseImpl() {
 #elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
   /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
   pthread_attr_get_np(thread, &sattr);
+#elif defined(__sun)
 #else
   /*
    * FIXME: this function is non-portable;
