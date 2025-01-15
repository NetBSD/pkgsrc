$NetBSD: patch-src_lib_asiolink_io__service.cc,v 1.1 2025/01/15 06:05:14 wiz Exp $

Fix build with boost 1.87.
https://github.com/isc-projects/kea/pull/143

--- src/lib/asiolink/io_service.cc.orig	2024-07-25 08:50:58.000000000 +0000
+++ src/lib/asiolink/io_service.cc
@@ -30,7 +30,7 @@ public:
     /// @brief The constructor.
     IOServiceImpl() :
         io_service_(),
-        work_(new boost::asio::io_service::work(io_service_)) {
+        work_(boost::asio::make_work_guard(io_service_)) {
     };
 
     /// @brief The destructor.
@@ -92,7 +92,7 @@ public:
 
     /// @brief Restarts the IOService in preparation for a subsequent @ref run() invocation.
     void restart() {
-        io_service_.reset();
+        io_service_.restart();
     }
 
     /// @brief Removes IO service work object to let it finish running
@@ -115,12 +115,12 @@ public:
     ///
     /// @param callback The callback to be run on the IO service.
     void post(const std::function<void ()>& callback) {
-        io_service_.post(callback);
+        boost::asio::post(io_service_, callback);
     }
 
 private:
     boost::asio::io_service io_service_;
-    boost::shared_ptr<boost::asio::io_service::work> work_;
+    boost::asio::executor_work_guard<boost::asio::io_service::executor_type> work_;
 };
 
 IOService::IOService() : io_impl_(new IOServiceImpl()) {
