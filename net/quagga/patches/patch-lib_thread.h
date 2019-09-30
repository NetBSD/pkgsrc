$NetBSD: patch-lib_thread.h,v 1.1 2019/09/30 08:57:49 kardel Exp $

 - add a name to a thread for error messages
 - add a list pointer to the thread to track list membership

--- lib/thread.h.orig	2018-02-19 21:24:55.000000000 +0000
+++ lib/thread.h
@@ -38,6 +38,7 @@ struct rusage_t
 /* Linked list of thread. */
 struct thread_list
 {
+  const char    *name;
   struct thread *head;
   struct thread *tail;
   int count;
@@ -77,6 +78,7 @@ struct thread
   thread_type add_type;		/* thread type */
   struct thread *next;		/* next pointer of the thread */   
   struct thread *prev;		/* previous pointer of the thread */
+  struct thread_list *list;	/* current list we are queued in */
   struct thread_master *master;	/* pointer to the struct thread_master. */
   int (*func) (struct thread *); /* event function */
   void *arg;			/* event argument */
