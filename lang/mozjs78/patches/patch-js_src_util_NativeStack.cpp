$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.1 2020/12/06 10:50:03 nia Exp $

illumos pthreads don't have pthread_getattr_np.

--- js/src/util/NativeStack.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -13,7 +13,7 @@
 #  if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    include <pthread_np.h>
 #  endif
-#  if defined(SOLARIS) || defined(AIX)
+#  if defined(__sun) || defined(AIX)
 #    include <ucontext.h>
 #  endif
 #  if defined(ANDROID) && !defined(__aarch64__)
@@ -128,6 +128,7 @@ void* js::GetNativeStackBaseImpl() {
 #    elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
   /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
   pthread_attr_get_np(thread, &sattr);
+#    elif defined(__sun)
 #    else
   /*
    * FIXME: this function is non-portable;
