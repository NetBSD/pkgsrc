$NetBSD: patch-glib_gthread-posix.c,v 1.2 2014/09/14 23:35:23 prlw1 Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=736651

--- glib/gthread-posix.c.orig	2014-02-22 15:29:07.000000000 +0000
+++ glib/gthread-posix.c
@@ -644,6 +644,7 @@ g_cond_impl_new (void)
 #elif defined (HAVE_PTHREAD_CONDATTR_SETCLOCK) && defined (CLOCK_MONOTONIC)
   if G_UNLIKELY ((status = pthread_condattr_setclock (&attr, CLOCK_MONOTONIC)) != 0)
     g_thread_abort (status, "pthread_condattr_setclock");
+#elif defined (CLOCK_MONOTONIC)
 #else
 #error Cannot support GCond on your platform.
 #endif
@@ -892,6 +893,21 @@ g_cond_wait_until (GCond  *cond,
     if ((status = pthread_cond_timedwait (g_cond_get_impl (cond), g_mutex_get_impl (mutex), &ts)) == 0)
       return TRUE;
   }
+#elif defined (CLOCK_MONOTONIC)
+  {
+    gint64 monotonic_now = g_get_monotonic_time ();
+    gint64 real_end_time;
+
+    if (end_time <= monotonic_now)
+      return FALSE;
+
+    real_end_time = g_get_real_time () + (end_time - monotonic_now);
+
+    ts.tv_sec = real_end_time / 1000000;
+    ts.tv_nsec = (real_end_time % 1000000) * 1000;
+    if ((status = pthread_cond_timedwait (g_cond_get_impl (cond), g_mutex_get_impl (mutex), &ts)) == 0)
+      return TRUE;
+  }
 #else
 #error Cannot support GCond on your platform.
 #endif
