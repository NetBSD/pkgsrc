$NetBSD: patch-include_violite.h,v 1.1 2022/11/27 22:12:25 nia Exp $

pthread_t on NetBSD is a pointer to a struct. To account for the
C++ type system we need to use an actual NULL pointer rather than
an incompatible integer type.

--- include/violite.h.orig	2022-09-13 16:15:16.000000000 +0000
+++ include/violite.h
@@ -343,7 +343,11 @@ struct Vio {
     It is initialized to 0 here, meaning don't attempt to send a signal, to
     keep non-server code unaffected.
   */
+#ifdef __NetBSD__
+  std::optional<my_thread_t> thread_id = nullptr;
+#else
   std::optional<my_thread_t> thread_id = 0;
+#endif
   sigset_t signal_mask;  // Signal mask
   /*
     Flag to indicate whether we are in poll or shutdown.
