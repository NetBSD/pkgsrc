$NetBSD: patch-lib_base_io-engine.hpp,v 1.1 2025/02/19 18:02:21 wiz Exp $

Support boost 1.87.
https://github.com/Icinga/icinga2/pull/10278

--- lib/base/io-engine.hpp.orig	2025-02-05 14:12:30.000000000 +0000
+++ lib/base/io-engine.hpp
@@ -16,11 +16,16 @@
 #include <utility>
 #include <vector>
 #include <stdexcept>
+#include <boost/context/fixedsize_stack.hpp>
 #include <boost/exception/all.hpp>
 #include <boost/asio/deadline_timer.hpp>
 #include <boost/asio/io_context.hpp>
 #include <boost/asio/spawn.hpp>
 
+#if BOOST_VERSION >= 108000
+#	include <boost/asio/detached.hpp>
+#endif // BOOST_VERSION >= 108000
+
 namespace icinga
 {
 
@@ -102,21 +107,32 @@ public:
 	static void SpawnCoroutine(Handler& h, Function f) {
 
 		boost::asio::spawn(h,
+#if BOOST_VERSION >= 108000
+			std::allocator_arg_t(),
+			boost::context::fixedsize_stack(GetCoroutineStackSize()),
+#endif // BOOST_VERSION >= 108000
 			[f](boost::asio::yield_context yc) {
 
 				try {
 					f(yc);
-				} catch (const boost::coroutines::detail::forced_unwind &) {
-					// Required for proper stack unwinding when coroutines are destroyed.
-					// https://github.com/boostorg/coroutine/issues/39
-					throw;
 				} catch (const std::exception& ex) {
 					Log(LogCritical, "IoEngine") << "Exception in coroutine: " << DiagnosticInformation(ex);
 				} catch (...) {
-					Log(LogCritical, "IoEngine", "Exception in coroutine!");
+					try {
+						Log(LogCritical, "IoEngine", "Exception in coroutine!");
+					} catch (...) {
+					}
+
+					// Required for proper stack unwinding when coroutines are destroyed.
+					// https://github.com/boostorg/coroutine/issues/39
+					throw;
 				}
 			},
+#if BOOST_VERSION >= 108000
+			boost::asio::detached
+#else // BOOST_VERSION >= 108000
 			boost::coroutines::attributes(GetCoroutineStackSize()) // Set a pre-defined stack size.
+#endif // BOOST_VERSION >= 108000
 		);
 	}
 
