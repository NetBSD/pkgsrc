$NetBSD: patch-boost_asio_detail_impl_select__reactor.ipp,v 1.1 2014/08/18 10:35:13 fhajny Exp $

Revert a upstream Windows optimization commit that breaks /dev/poll platforms
like SunOS. See https://svn.boost.org/trac/boost/ticket/10350

--- boost/asio/detail/impl/select_reactor.ipp.orig	2014-08-13 12:13:05.240414272 +0000
+++ boost/asio/detail/impl/select_reactor.ipp
@@ -182,7 +182,7 @@ void select_reactor::run(bool block, op_
   for (int i = 0; i < max_select_ops; ++i)
   {
     have_work_to_do = have_work_to_do || !op_queue_[i].empty();
-    fd_sets_[i].set(op_queue_[i], ops);
+    op_queue_[i].get_descriptors(fd_sets_[i], ops);
     if (fd_sets_[i].max_descriptor() > max_fd)
       max_fd = fd_sets_[i].max_descriptor();
   }
@@ -190,10 +190,10 @@ void select_reactor::run(bool block, op_
 #if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
   // Connection operations on Windows use both except and write fd_sets.
   have_work_to_do = have_work_to_do || !op_queue_[connect_op].empty();
-  fd_sets_[write_op].set(op_queue_[connect_op], ops);
+  op_queue_[connect_op].get_descriptors(fd_sets_[write_op], ops);
   if (fd_sets_[write_op].max_descriptor() > max_fd)
     max_fd = fd_sets_[write_op].max_descriptor();
-  fd_sets_[except_op].set(op_queue_[connect_op], ops);
+  op_queue_[connect_op].get_descriptors(fd_sets_[except_op], ops);
   if (fd_sets_[except_op].max_descriptor() > max_fd)
     max_fd = fd_sets_[except_op].max_descriptor();
 #endif // defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
@@ -228,14 +228,16 @@ void select_reactor::run(bool block, op_
   {
 #if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
     // Connection operations on Windows use both except and write fd_sets.
-    fd_sets_[except_op].perform(op_queue_[connect_op], ops);
-    fd_sets_[write_op].perform(op_queue_[connect_op], ops);
+    op_queue_[connect_op].perform_operations_for_descriptors(
+        fd_sets_[except_op], ops);
+    op_queue_[connect_op].perform_operations_for_descriptors(
+        fd_sets_[write_op], ops);
 #endif // defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
 
     // Exception operations must be processed first to ensure that any
     // out-of-band data is read before normal data.
     for (int i = max_select_ops - 1; i >= 0; --i)
-      fd_sets_[i].perform(op_queue_[i], ops);
+      op_queue_[i].perform_operations_for_descriptors(fd_sets_[i], ops);
   }
   timer_queues_.get_ready_timers(ops);
 }
