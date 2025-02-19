$NetBSD: patch-lib_remote_apilistener.cpp,v 1.1 2025/02/19 18:02:21 wiz Exp $

Support boost 1.87.
https://github.com/Icinga/icinga2/pull/10278

--- lib/remote/apilistener.cpp.orig	2025-02-05 14:12:30.000000000 +0000
+++ lib/remote/apilistener.cpp
@@ -439,9 +439,7 @@ bool ApiListener::AddListener(const Stri
 
 	try {
 		tcp::resolver resolver (io);
-		tcp::resolver::query query (node, service, tcp::resolver::query::passive);
-
-		auto result (resolver.resolve(query));
+		auto result (resolver.resolve(node.CStr(), service.CStr(), tcp::resolver::passive));
 		auto current (result.begin());
 
 		for (;;) {
