$NetBSD: patch-src_actions.cpp,v 1.1 2018/02/01 16:45:57 he Exp $

PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP is non-portable.
This just protects a few statements and a variable increase;
it's unlikely the recursivity is really needed.

--- src/actions.cpp.orig	2017-03-08 20:42:28.000000000 +0000
+++ src/actions.cpp
@@ -2049,7 +2049,11 @@ namespace {
   /* This is the critical section object (statically allocated). */
   static pthread_mutex_t cs =  PTHREAD_RECURSIVE_MUTEX_INITIALIZER;
  #else
-  static pthread_mutex_t cs =  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+  #if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
+   static pthread_mutex_t cs =  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+  #else
+   static pthread_mutex_t cs =  PTHREAD_MUTEX_INITIALIZER;
+  #endif
  #endif
 #endif
 
