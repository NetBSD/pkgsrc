$NetBSD: patch-lib_thread.c,v 1.1 2019/09/30 08:57:49 kardel Exp $

 - add fast check on prev/next pointer invariants
 - add check to detect inserting of a thread already in a list
 - add check to detect deletion of a thread not in a list
 - ignore cancellation requests for the currently running thread (fixes crash)
 - fix setting of prey/next pointers on adjecant elements when a head/tail element is
   deleted

--- lib/thread.c.orig	2018-02-19 21:24:55.000000000 +0000
+++ lib/thread.c
@@ -531,6 +531,10 @@ thread_master_create ()
       return NULL;
     }
 
+  rv->ready.name = "ready";
+  rv->event.name = "event";
+  rv->unuse.name = "unuse";
+
   rv->fd_limit = (int)limit.rlim_cur;
   rv->read = XCALLOC (MTYPE_THREAD, sizeof (struct thread *) * rv->fd_limit);
   if (rv->read == NULL)
@@ -560,6 +564,11 @@ thread_master_create ()
 static void
 thread_list_add (struct thread_list *list, struct thread *thread)
 {
+  if (thread->list) {
+      zlog_err("%s:%d: thread_list_add INCONSISTENCY thread %p is already linked in list %s", __FILE__, __LINE__, thread, thread->list->name);
+      assert(!thread->list);
+  }
+
   thread->next = NULL;
   thread->prev = list->tail;
   if (list->tail)
@@ -568,22 +577,57 @@ thread_list_add (struct thread_list *lis
     list->head = thread;
   list->tail = thread;
   list->count++;
+  thread->list = list;
 }
 
 /* Delete a thread from the list. */
 static struct thread *
 thread_list_delete (struct thread_list *list, struct thread *thread)
 {
+  if (!thread->list) {
+      zlog_err("%s:%d: thread_list_delete INCONSISTENCY thread %p is NOT linked in a list", __FILE__, __LINE__, thread);
+      assert(thread->list);
+  }
+
+  if (thread->list && thread->list != list) {
+      zlog_err("%s:%d: thread_list_delete INCONSISTENCY thread %p is linked in list %s but should be removed from list %s",
+      __FILE__, __LINE__, thread, thread->list->name, list->name);
+      assert(thread->list == list);
+  }
+
   if (thread->next)
     thread->next->prev = thread->prev;
-  else
+  else {
+    if (list->tail != thread) {
+      zlog_debug("%s:%d: thread_list_delete INCONSISTENCY thread %p has no successor but list->tail points to %p in list %s",
+      __FILE__, __LINE__, thread, list->tail, list->name);
+      assert(list->tail == thread);
+    }
+
     list->tail = thread->prev;
+    if (list->tail)
+      list->tail->next = NULL;
+  }
+
   if (thread->prev)
     thread->prev->next = thread->next;
-  else
+  else {
+    if (list->head != thread) {
+      zlog_debug("%s:%d: thread_list_delete INCONSISTENCY thread %p has no predecessor but list->head points to %p in list %s",
+      __FILE__, __LINE__, thread, list->head, list->name);
+      assert(list->head == thread);
+    }
+
     list->head = thread->next;
-  thread->next = thread->prev = NULL;
+    if (list->head)
+	list->head->prev = NULL;
+  }
+
   list->count--;
+
+  thread->next = thread->prev = NULL;
+  thread->list = NULL;
+
   return thread;
 }
 
@@ -603,10 +647,12 @@ thread_add_fd (struct thread **thread_ar
 static void
 thread_add_unuse (struct thread *thread)
 {
-  thread->type = THREAD_UNUSED;
   assert (thread->master != NULL && thread != NULL);
+  assert (thread_current != thread);
   assert (thread->next == NULL);
   assert (thread->prev == NULL);
+  assert (thread->list == NULL);
+  thread->type = THREAD_UNUSED;
   thread_list_add (&thread->master->unuse, thread);
 }
 
@@ -948,7 +994,15 @@ thread_cancel (struct thread *thread)
   struct thread_list *list = NULL;
   struct pqueue *queue = NULL;
   struct thread **thread_array = NULL;
-  
+ 
+  /*
+   * we cannot cancel ourself when running.
+   * cancellation of ourself would lead to a double entry attempt
+   * into the unuse list.
+   */
+  if (thread_current == thread)
+	return;
+
   switch (thread->type)
     {
     case THREAD_READ:
@@ -1175,7 +1229,7 @@ thread_fetch (struct thread_master *m)
       exceptfd = fd_copy_fd_set(m->exceptfd);
       
       /* Calculate select wait timer if nothing else to do */
-      if (m->ready.count == 0)
+      if (thread_empty(&m->ready))
         {
           quagga_get_relative (NULL);
           timer_wait = thread_timer_wait (m->timer, &timer_val);
