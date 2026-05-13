$NetBSD: patch-lib_message_mu-message-part.cc,v 1.1 2026/05/13 18:34:47 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/message/mu-message-part.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/message/mu-message-part.cc
@@ -49,7 +49,7 @@ cook(const std::string& fname, const std::vector<char>
 	clean.reserve(fname.length());
 
 	for (auto& c: basename(fname))
-		if (seq_some(forbidden,[&](char fc){return ::iscntrl(c) || c == fc;}))
+		if (seq_some(forbidden,[&](char fc){return ::iscntrl(static_cast<unsigned char>(c)) || c == fc;}))
 			clean += '-';
 		else
 			clean += c;
