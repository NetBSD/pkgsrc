$NetBSD: patch-boost_asio_detail_reactor__op__queue.hpp,v 1.1 2014/08/18 10:35:13 fhajny Exp $

Revert a upstream Windows optimization commit that breaks /dev/poll platforms
like SunOS. See https://svn.boost.org/trac/boost/ticket/10350

--- boost/asio/detail/reactor_op_queue.hpp.orig	2014-08-13 12:13:05.258739735 +0000
+++ boost/asio/detail/reactor_op_queue.hpp
@@ -33,54 +33,41 @@ class reactor_op_queue
   : private noncopyable
 {
 public:
-  typedef Descriptor key_type;
-
-  struct mapped_type : op_queue<reactor_op>
-  {
-    mapped_type() {}
-    mapped_type(const mapped_type&) {}
-    void operator=(const mapped_type&) {}
-  };
-
-  typedef typename hash_map<key_type, mapped_type>::value_type value_type;
-  typedef typename hash_map<key_type, mapped_type>::iterator iterator;
-
   // Constructor.
   reactor_op_queue()
     : operations_()
   {
   }
 
-  // Obtain iterators to all registered descriptors.
-  iterator begin() { return operations_.begin(); }
-  iterator end() { return operations_.end(); }
-
   // Add a new operation to the queue. Returns true if this is the only
   // operation for the given descriptor, in which case the reactor's event
   // demultiplexing function call may need to be interrupted and restarted.
   bool enqueue_operation(Descriptor descriptor, reactor_op* op)
   {
+    typedef typename operations_map::iterator iterator;
+    typedef typename operations_map::value_type value_type;
     std::pair<iterator, bool> entry =
-      operations_.insert(value_type(descriptor, mapped_type()));
-    entry.first->second.push(op);
+      operations_.insert(value_type(descriptor, operations()));
+    entry.first->second.op_queue_.push(op);
     return entry.second;
   }
 
-  // Cancel all operations associated with the descriptor identified by the
-  // supplied iterator. Any operations pending for the descriptor will be
-  // cancelled. Returns true if any operations were cancelled, in which case
-  // the reactor's event demultiplexing function may need to be interrupted and
-  // restarted.
-  bool cancel_operations(iterator i, op_queue<operation>& ops,
+  // Cancel all operations associated with the descriptor. Any operations
+  // pending for the descriptor will be notified that they have been cancelled
+  // next time perform_cancellations is called. Returns true if any operations
+  // were cancelled, in which case the reactor's event demultiplexing function
+  // may need to be interrupted and restarted.
+  bool cancel_operations(Descriptor descriptor, op_queue<operation>& ops,
       const boost::system::error_code& ec =
         boost::asio::error::operation_aborted)
   {
+    typename operations_map::iterator i = operations_.find(descriptor);
     if (i != operations_.end())
     {
-      while (reactor_op* op = i->second.front())
+      while (reactor_op* op = i->second.op_queue_.front())
       {
         op->ec_ = ec;
-        i->second.pop();
+        i->second.op_queue_.pop();
         ops.push(op);
       }
       operations_.erase(i);
@@ -90,17 +77,6 @@ public:
     return false;
   }
 
-  // Cancel all operations associated with the descriptor. Any operations
-  // pending for the descriptor will be cancelled. Returns true if any
-  // operations were cancelled, in which case the reactor's event
-  // demultiplexing function may need to be interrupted and restarted.
-  bool cancel_operations(Descriptor descriptor, op_queue<operation>& ops,
-      const boost::system::error_code& ec =
-        boost::asio::error::operation_aborted)
-  {
-    return this->cancel_operations(operations_.find(descriptor), ops, ec);
-  }
-
   // Whether there are no operations in the queue.
   bool empty() const
   {
@@ -113,18 +89,18 @@ public:
     return operations_.find(descriptor) != operations_.end();
   }
 
-  // Perform the operations corresponding to the descriptor identified by the
-  // supplied iterator. Returns true if there are still unfinished operations
-  // queued for the descriptor.
-  bool perform_operations(iterator i, op_queue<operation>& ops)
+  // Perform the operations corresponding to the descriptor. Returns true if
+  // there are still unfinished operations queued for the descriptor.
+  bool perform_operations(Descriptor descriptor, op_queue<operation>& ops)
   {
+    typename operations_map::iterator i = operations_.find(descriptor);
     if (i != operations_.end())
     {
-      while (reactor_op* op = i->second.front())
+      while (reactor_op* op = i->second.op_queue_.front())
       {
         if (op->perform())
         {
-          i->second.pop();
+          i->second.op_queue_.pop();
           ops.push(op);
         }
         else
@@ -137,28 +113,84 @@ public:
     return false;
   }
 
-  // Perform the operations corresponding to the descriptor. Returns true if
-  // there are still unfinished operations queued for the descriptor.
-  bool perform_operations(Descriptor descriptor, op_queue<operation>& ops)
+  // Fill a descriptor set with the descriptors corresponding to each active
+  // operation. The op_queue is used only when descriptors fail to be added to
+  // the descriptor set.
+  template <typename Descriptor_Set>
+  void get_descriptors(Descriptor_Set& descriptors, op_queue<operation>& ops)
   {
-    return this->perform_operations(operations_.find(descriptor), ops);
+    typename operations_map::iterator i = operations_.begin();
+    while (i != operations_.end())
+    {
+      Descriptor descriptor = i->first;
+      ++i;
+      if (!descriptors.set(descriptor))
+      {
+        boost::system::error_code ec(error::fd_set_failure);
+        cancel_operations(descriptor, ops, ec);
+      }
+    }
+  }
+
+  // Perform the operations corresponding to the ready file descriptors
+  // contained in the given descriptor set.
+  template <typename Descriptor_Set>
+  void perform_operations_for_descriptors(
+      const Descriptor_Set& descriptors, op_queue<operation>& ops)
+  {
+    typename operations_map::iterator i = operations_.begin();
+    while (i != operations_.end())
+    {
+      typename operations_map::iterator op_iter = i++;
+      if (descriptors.is_set(op_iter->first))
+      {
+        while (reactor_op* op = op_iter->second.op_queue_.front())
+        {
+          if (op->perform())
+          {
+            op_iter->second.op_queue_.pop();
+            ops.push(op);
+          }
+          else
+          {
+            break;
+          }
+        }
+
+        if (op_iter->second.op_queue_.empty())
+          operations_.erase(op_iter);
+      }
+    }
   }
 
   // Get all operations owned by the queue.
   void get_all_operations(op_queue<operation>& ops)
   {
-    iterator i = operations_.begin();
+    typename operations_map::iterator i = operations_.begin();
     while (i != operations_.end())
     {
-      iterator op_iter = i++;
-      ops.push(op_iter->second);
+      typename operations_map::iterator op_iter = i++;
+      ops.push(op_iter->second.op_queue_);
       operations_.erase(op_iter);
     }
   }
 
 private:
+  struct operations
+  {
+    operations() {}
+    operations(const operations&) {}
+    void operator=(const operations&) {}
+
+    // The operations waiting on the desccriptor.
+    op_queue<reactor_op> op_queue_;
+  };
+
+  // The type for a map of operations.
+  typedef hash_map<Descriptor, operations> operations_map;
+
   // The operations that are currently executing asynchronously.
-  hash_map<key_type, mapped_type> operations_;
+  operations_map operations_;
 };
 
 } // namespace detail
