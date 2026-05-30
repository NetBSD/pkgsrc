$NetBSD: patch-lib_utils_mu-utils.cc,v 1.2 2026/05/30 12:56:30 ryoon Exp $

ctype(3) for NetBSD 11

--- lib/utils/mu-utils.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/utils/mu-utils.cc
@@ -167,7 +167,7 @@ asciify_in_place (char *buf)
 	g_return_val_if_fail (buf, NULL);
 
 	for (c = buf; c && *c; ++c) {
-		if ((!isprint(*c) && !isspace (*c)) || !isascii(*c))
+		if ((!isprint(static_cast<unsigned char>(*c)) && !isspace (static_cast<unsigned char>(*c))) || !isascii(static_cast<unsigned char>(*c)))
 			*c = '.';
 	}
 
@@ -269,7 +269,7 @@ Mu::remove_ctrl(const std::string& str)
 	result.reserve(str.length());
 
 	for (auto&& c : str) {
-		if (::iscntrl(c) || c == ' ') {
+		if (::iscntrl(static_cast<unsigned char>(c)) || c == ' ') {
 			if (prev != ' ')
 				result += prev = ' ';
 		} else
