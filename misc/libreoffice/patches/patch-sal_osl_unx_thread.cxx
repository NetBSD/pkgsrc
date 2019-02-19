$NetBSD: patch-sal_osl_unx_thread.cxx,v 1.1 2019/02/19 16:28:03 ryoon Exp $

--- sal/osl/unx/thread.cxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ sal/osl/unx/thread.cxx
@@ -88,11 +88,11 @@ typedef struct osl_thread_impl_st
 
 struct osl_thread_priority_st
 {
-    int const m_Highest;
-    int const m_Above_Normal;
-    int const m_Normal;
-    int const m_Below_Normal;
-    int const m_Lowest;
+    int m_Highest;
+    int m_Above_Normal;
+    int m_Normal;
+    int m_Below_Normal;
+    int m_Lowest;
 };
 
 #define OSL_THREAD_PRIORITY_INITIALIZER { 127, 96, 64, 32, 0 }
@@ -110,7 +110,7 @@ static void osl_thread_textencoding_init
 struct osl_thread_global_st
 {
     pthread_once_t                    m_once;
-    struct osl_thread_priority_st const m_priority;
+    struct osl_thread_priority_st m_priority;
     struct osl_thread_textencoding_st m_textencoding;
 };
 
