$NetBSD: patch-lib_message_mu-contact.hh,v 1.2 2026/08/11 14:40:34 ktnb Exp $

Fix error -30 on NetBSD 11

--- lib/message/mu-contact.hh.orig	2026-08-09 13:09:55.896030812 +0000
+++ lib/message/mu-contact.hh
@@ -166,7 +166,7 @@ struct Contact { (private)
 private:
 	void cleanup_name() { // replace control characters by spaces.
 		for (auto& c: name)
-			if (is_ascii_cntrl(c))
+			if (is_ascii_cntrl(static_cast<unsigned char>(c)))
 				c = ' ';
 	}
 
