$NetBSD: patch-js_src_jsnativestack.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- js/src/jsnativestack.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/jsnativestack.cpp
@@ -59,7 +59,7 @@ js::GetNativeStackBaseImpl()
 # endif
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 #include <ucontext.h>
 
@@ -105,6 +105,7 @@ js::GetNativeStackBaseImpl()
 #  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
+#  elif defined(__sun)
 #  else
     /*
      * FIXME: this function is non-portable;
