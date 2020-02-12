$NetBSD: patch-libgc_pthread__stop__world.c,v 1.1 2020/02/12 15:25:16 ryoon Exp $

* Workaround for NetBSD's pthread_equal

--- libgc/pthread_stop_world.c.orig	2020-02-04 17:00:30.000000000 +0000
+++ libgc/pthread_stop_world.c
@@ -259,7 +259,7 @@ static void pthread_push_all_stacks()
     for (i = 0; i < THREAD_TABLE_SZ; i++) {
       for (p = GC_threads[i]; p != 0; p = p -> next) {
         if (p -> flags & FINISHED) continue;
-        if (pthread_equal(p -> id, me)) {
+        if ((p -> id == me)) {
 #  	    ifdef SPARC
 	        lo = (ptr_t)GC_save_regs_in_stack();
 #  	    else
@@ -305,7 +305,7 @@ static void pthread_push_all_stacks()
     	        (unsigned long) p -> id,
 		(unsigned long) bs_lo, (unsigned long) bs_hi);
 #	  endif
-          if (pthread_equal(p -> id, me)) {
+          if ((p -> id == me)) {
 	    GC_push_all_eager(bs_lo, bs_hi);
 	  } else {
 	    GC_push_all_stack(bs_lo, bs_hi);
