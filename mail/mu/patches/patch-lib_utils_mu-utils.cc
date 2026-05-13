$NetBSD: patch-lib_utils_mu-utils.cc,v 1.1 2026/05/13 18:34:47 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/utils/mu-utils.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/utils/mu-utils.cc
@@ -269,7 +269,7 @@ Mu::remove_ctrl(const std::string& str)
 	result.reserve(str.length());
 
 	for (auto&& c : str) {
-		if (::iscntrl(c) || c == ' ') {
+		if (::iscntrl(static_cast<unsigned char>(c)) || c == ' ') {
 			if (prev != ' ')
 				result += prev = ' ';
 		} else
