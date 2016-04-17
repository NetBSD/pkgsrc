$NetBSD: patch-mozilla_js_src_jsnativestack.cpp,v 1.1 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/src/jsnativestack.cpp.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/js/src/jsnativestack.cpp
@@ -102,7 +102,7 @@ js::GetNativeStackBaseImpl()
     pthread_attr_init(&sattr);
 #  if defined(__OpenBSD__)
     stack_t ss;
-#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
+#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(__DragonFly__) || defined(NETBSD) || defined(__NetBSD__) /* XXX tnn not sure why NETBSD isn't defined, it looks like it should be ... */
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
 #  else
