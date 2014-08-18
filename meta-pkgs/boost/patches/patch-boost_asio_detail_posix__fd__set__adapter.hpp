$NetBSD: patch-boost_asio_detail_posix__fd__set__adapter.hpp,v 1.1 2014/08/18 10:35:13 fhajny Exp $

Revert a upstream Windows optimization commit that breaks /dev/poll platforms
like SunOS. See https://svn.boost.org/trac/boost/ticket/10350

--- boost/asio/detail/posix_fd_set_adapter.hpp.orig	2014-08-13 12:13:05.246078647 +0000
+++ boost/asio/detail/posix_fd_set_adapter.hpp
@@ -23,7 +23,6 @@
 
 #include <cstring>
 #include <boost/asio/detail/noncopyable.hpp>
-#include <boost/asio/detail/reactor_op_queue.hpp>
 #include <boost/asio/detail/socket_types.hpp>
 
 #include <boost/asio/detail/push_options.hpp>
@@ -61,20 +60,6 @@ public:
     return false;
   }
 
-  void set(reactor_op_queue<socket_type>& operations, op_queue<operation>& ops)
-  {
-    reactor_op_queue<socket_type>::iterator i = operations.begin();
-    while (i != operations.end())
-    {
-      reactor_op_queue<socket_type>::iterator op_iter = i++;
-      if (!set(op_iter->first))
-      {
-        boost::system::error_code ec(error::fd_set_failure);
-        operations.cancel_operations(op_iter, ops, ec);
-      }
-    }
-  }
-
   bool is_set(socket_type descriptor) const
   {
     return FD_ISSET(descriptor, &fd_set_) != 0;
@@ -90,18 +75,6 @@ public:
     return max_descriptor_;
   }
 
-  void perform(reactor_op_queue<socket_type>& operations,
-      op_queue<operation>& ops) const
-  {
-    reactor_op_queue<socket_type>::iterator i = operations.begin();
-    while (i != operations.end())
-    {
-      reactor_op_queue<socket_type>::iterator op_iter = i++;
-      if (is_set(op_iter->first))
-        operations.perform_operations(op_iter, ops);
-    }
-  }
-
 private:
   mutable fd_set fd_set_;
   socket_type max_descriptor_;
