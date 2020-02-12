$NetBSD: patch-libgc_pthread__support.c,v 1.1 2020/02/12 15:25:16 ryoon Exp $

* Workaround for NetBSD's pthread_equal

--- libgc/pthread_support.c.orig	2020-02-04 17:00:30.000000000 +0000
+++ libgc/pthread_support.c
@@ -791,7 +791,7 @@ void GC_delete_thread(pthread_t id)
     nacl_gc_thread_self = NULL;
 #endif
 
-    while (!pthread_equal(p -> id, id)) {
+    while (!(p -> id == id)) {
         prev = p;
         p = p -> next;
     }
@@ -846,7 +846,7 @@ GC_thread GC_lookup_thread(pthread_t id)
     int hv = ((unsigned long)id) % THREAD_TABLE_SZ;
     register GC_thread p = GC_threads[hv];
     
-    while (p != 0 && !pthread_equal(p -> id, id)) p = p -> next;
+    while (p != 0 && !(p -> id == id)) p = p -> next;
     return(p);
 }
 
