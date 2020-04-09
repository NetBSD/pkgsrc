$NetBSD: patch-util_NativeStack.cpp,v 1.1 2020/04/09 09:40:47 jperkin Exp $

Fix build on SunOS/x86_64.

--- util/NativeStack.cpp.orig	2019-07-01 09:07:43.000000000 +0000
+++ util/NativeStack.cpp
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
