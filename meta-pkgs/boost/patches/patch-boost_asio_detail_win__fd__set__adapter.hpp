$NetBSD: patch-boost_asio_detail_win__fd__set__adapter.hpp,v 1.1 2014/08/18 10:35:13 fhajny Exp $

Revert a upstream Windows optimization commit that breaks /dev/poll platforms
like SunOS. See https://svn.boost.org/trac/boost/ticket/10350

--- boost/asio/detail/win_fd_set_adapter.hpp.orig	2014-08-13 12:13:05.251499093 +0000
+++ boost/asio/detail/win_fd_set_adapter.hpp
@@ -20,7 +20,6 @@
 #if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
 
 #include <boost/asio/detail/noncopyable.hpp>
-#include <boost/asio/detail/reactor_op_queue.hpp>
 #include <boost/asio/detail/socket_types.hpp>
 
 #include <boost/asio/detail/push_options.hpp>
@@ -62,20 +61,24 @@ public:
       if (fd_set_->fd_array[i] == descriptor)
         return true;
 
-    reserve(fd_set_->fd_count + 1);
-    fd_set_->fd_array[fd_set_->fd_count++] = descriptor;
-    return true;
-  }
-
-  void set(reactor_op_queue<socket_type>& operations, op_queue<operation>&)
-  {
-    reactor_op_queue<socket_type>::iterator i = operations.begin();
-    while (i != operations.end())
+    if (fd_set_->fd_count == capacity_)
     {
-      reactor_op_queue<socket_type>::iterator op_iter = i++;
-      reserve(fd_set_->fd_count + 1);
-      fd_set_->fd_array[fd_set_->fd_count++] = op_iter->first;
+      u_int new_capacity = capacity_ + capacity_ / 2;
+      win_fd_set* new_fd_set = static_cast<win_fd_set*>(::operator new(
+            sizeof(win_fd_set) - sizeof(SOCKET)
+            + sizeof(SOCKET) * (new_capacity)));
+
+      new_fd_set->fd_count = fd_set_->fd_count;
+      for (u_int i = 0; i < fd_set_->fd_count; ++i)
+        new_fd_set->fd_array[i] = fd_set_->fd_array[i];
+
+      ::operator delete(fd_set_);
+      fd_set_ = new_fd_set;
+      capacity_ = new_capacity;
     }
+
+    fd_set_->fd_array[fd_set_->fd_count++] = descriptor;
+    return true;
   }
 
   bool is_set(socket_type descriptor) const
@@ -94,14 +97,8 @@ public:
     return max_descriptor_;
   }
 
-  void perform(reactor_op_queue<socket_type>& operations,
-      op_queue<operation>& ops) const
-  {
-    for (u_int i = 0; i < fd_set_->fd_count; ++i)
-      operations.perform_operations(fd_set_->fd_array[i], ops);
-  }
-
 private:
+
   // This structure is defined to be compatible with the Windows API fd_set
   // structure, but without being dependent on the value of FD_SETSIZE. We use
   // the "struct hack" to allow the number of descriptors to be varied at
@@ -112,29 +109,6 @@ private:
     SOCKET fd_array[1];
   };
 
-  // Increase the fd_set_ capacity to at least the specified number of elements.
-  void reserve(u_int n)
-  {
-    if (n <= capacity_)
-      return;
-
-    u_int new_capacity = capacity_ + capacity_ / 2;
-    if (new_capacity < n)
-      new_capacity = n;
-
-    win_fd_set* new_fd_set = static_cast<win_fd_set*>(::operator new(
-          sizeof(win_fd_set) - sizeof(SOCKET)
-          + sizeof(SOCKET) * (new_capacity)));
-
-    new_fd_set->fd_count = fd_set_->fd_count;
-    for (u_int i = 0; i < fd_set_->fd_count; ++i)
-      new_fd_set->fd_array[i] = fd_set_->fd_array[i];
-
-    ::operator delete(fd_set_);
-    fd_set_ = new_fd_set;
-    capacity_ = new_capacity;
-  }
-
   win_fd_set* fd_set_;
   u_int capacity_;
   socket_type max_descriptor_;
