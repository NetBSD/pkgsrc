$NetBSD: patch-mysys_kqueue__timers.c,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- mysys/kqueue_timers.c.orig	2021-09-14 09:08:08.000000000 +0000
+++ mysys/kqueue_timers.c
@@ -74,8 +74,10 @@ timer_notify_thread_func(void *arg MY_AT
       assert(timer->id == kev.ident);
       timer->notify_function(timer);
     }
+#ifdef EVFILT_USER
     else if (kev.filter == EVFILT_USER)
       break;
+#endif
   }
 
   close(kq_fd);
@@ -96,7 +98,9 @@ start_helper_thread(void)
 {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, EV_ADD, 0, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, NULL, 0, NULL) < 0)
   {
@@ -150,7 +154,9 @@ my_timer_deinitialize(void)
 {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, 0, NOTE_TRIGGER, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, NULL, 0, NULL) < 0)
     my_message_local(ERROR_LEVEL,
