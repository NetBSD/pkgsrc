$NetBSD: patch-storage_perfschema_my__thread.h,v 1.1 2021/05/23 15:32:47 nia Exp $

Avoid type error on NetBSD.

--- storage/perfschema/my_thread.h.orig	2021-05-05 21:00:19.000000000 +0000
+++ storage/perfschema/my_thread.h
@@ -17,7 +17,7 @@
 typedef pthread_key_t thread_local_key_t;
 typedef pthread_t my_thread_handle;
 typedef pthread_attr_t my_thread_attr_t;
-typedef uint32 my_thread_os_id_t;
+typedef intptr_t my_thread_os_id_t;
 
 #define LOCK_plugin_delete LOCK_plugin
 
@@ -73,7 +73,7 @@ static inline my_thread_os_id_t my_threa
 #else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
   /* Unknown platform, fallback. */
-  return pthread_self();
+  return (intptr_t)pthread_self();
 #else
   /* Feature not available. */
   return 0;
