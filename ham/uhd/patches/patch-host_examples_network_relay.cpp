$NetBSD: patch-host_examples_network_relay.cpp,v 1.1 2018/03/09 11:36:40 mef Exp $

PR pkg/52969
with the boost libs updated to 2.6 there are changes so that socket->native()
is no longer supported. use socket->native_handle() instead

--- examples/network_relay.cpp.orig
+++ examples/network_relay.cpp
@@ -127,7 +127,7 @@
         wait_for_thread.notify_one();    // notify constructor that this thread has started
         std::vector<char> buff(insane_mtu);
         while (not boost::this_thread::interruption_requested()){
-            if (wait_for_recv_ready(_server_socket->native())){
+            if (wait_for_recv_ready(_server_socket->native_handle())){
                 boost::mutex::scoped_lock lock(_endpoint_mutex);
                 const size_t len = _server_socket->receive_from(asio::buffer(&buff.front(), buff.size()), _endpoint);
                 lock.unlock();
@@ -153,7 +153,7 @@
         wait_for_thread.notify_one();    // notify constructor that this thread has started
         std::vector<char> buff(insane_mtu);
         while (not boost::this_thread::interruption_requested()){
-            if (wait_for_recv_ready(_client_socket->native())){
+            if (wait_for_recv_ready(_client_socket->native_handle())){
                 const size_t len = _client_socket->receive(asio::buffer(&buff.front(), buff.size()));
                 boost::mutex::scoped_lock lock(_endpoint_mutex);
                 _server_socket->send_to(asio::buffer(&buff.front(), len), _endpoint);

patch-host_lib_transport_tcp_zero_copy.cpp
