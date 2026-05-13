$NetBSD: patch-lib_mu-query-processor.cc,v 1.1 2026/05/13 18:34:47 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/mu-query-processor.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/mu-query-processor.cc
@@ -437,7 +437,7 @@ process(const std::string& expr)
 	/* all control chars become SPC */
 	std::string str{expr};
 	for (auto& c: str)
-		c = ::iscntrl(c) ? ' ' : c;
+		c = ::iscntrl(static_cast<unsigned char>(c)) ? ' ' : c;
 
 	while(!str.empty()) {
 		auto&& element = next_element(str, offset)
