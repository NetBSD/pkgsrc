$NetBSD: patch-boost_asio_detail_dev__poll__reactor.hpp,v 1.1 2023/05/03 13:58:18 jperkin Exp $

Build fix - https://github.com/chriskohlhoff/asio/pull/1282

--- boost/asio/detail/dev_poll_reactor.hpp.orig	2023-05-03 13:27:22.571218912 +0000
+++ boost/asio/detail/dev_poll_reactor.hpp
@@ -109,7 +109,7 @@ public:
   {
     start_op(op_type, descriptor, descriptor_data,
         op, is_continuation, allow_speculative,
-        &epoll_reactor::call_post_immediate_completion, this);
+        &dev_poll_reactor::call_post_immediate_completion, this);
   }
 
 
