$NetBSD: patch-lib_icingadb_redisconnection.hpp,v 1.1 2025/02/19 18:02:21 wiz Exp $

Support boost 1.87.
https://github.com/Icinga/icinga2/pull/10278

--- lib/icingadb/redisconnection.hpp.orig	2025-02-05 14:12:30.000000000 +0000
+++ lib/icingadb/redisconnection.hpp
@@ -388,9 +388,7 @@ RedisConnection::Reply RedisConnection::
 
 	try {
 		return ReadRESP(*strm, yc);
-	} catch (const boost::coroutines::detail::forced_unwind&) {
-		throw;
-	} catch (...) {
+	} catch (const std::exception&) {
 		if (m_Connecting.exchange(false)) {
 			m_Connected.store(false);
 			stream = nullptr;
@@ -403,6 +401,8 @@ RedisConnection::Reply RedisConnection::
 		}
 
 		throw;
+	} catch (...) {
+		throw;
 	}
 }
 
@@ -426,9 +426,7 @@ void RedisConnection::WriteOne(StreamPtr
 	try {
 		WriteRESP(*strm, query, yc);
 		strm->async_flush(yc);
-	} catch (const boost::coroutines::detail::forced_unwind&) {
-		throw;
-	} catch (...) {
+	} catch (const std::exception&) {
 		if (m_Connecting.exchange(false)) {
 			m_Connected.store(false);
 			stream = nullptr;
@@ -441,6 +439,8 @@ void RedisConnection::WriteOne(StreamPtr
 		}
 
 		throw;
+	} catch (...) {
+		throw;
 	}
 }
 
