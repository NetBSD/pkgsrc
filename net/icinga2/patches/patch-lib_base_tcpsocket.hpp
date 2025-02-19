$NetBSD: patch-lib_base_tcpsocket.hpp,v 1.1 2025/02/19 18:02:21 wiz Exp $

Support boost 1.87.
https://github.com/Icinga/icinga2/pull/10278

--- lib/base/tcpsocket.hpp.orig	2025-02-05 14:12:30.000000000 +0000
+++ lib/base/tcpsocket.hpp
@@ -41,8 +41,7 @@ void Connect(Socket& socket, const Strin
 	using boost::asio::ip::tcp;
 
 	tcp::resolver resolver (IoEngine::Get().GetIoContext());
-	tcp::resolver::query query (node, service);
-	auto result (resolver.resolve(query));
+	auto result (resolver.resolve(node.CStr(), service.CStr()));
 	auto current (result.begin());
 
 	for (;;) {
@@ -72,8 +71,7 @@ void Connect(Socket& socket, const Strin
 	using boost::asio::ip::tcp;
 
 	tcp::resolver resolver (IoEngine::Get().GetIoContext());
-	tcp::resolver::query query (node, service);
-	auto result (resolver.async_resolve(query, yc));
+	auto result (resolver.async_resolve(node.CStr(), service.CStr(), yc));
 	auto current (result.begin());
 
 	for (;;) {
