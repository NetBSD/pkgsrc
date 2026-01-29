$NetBSD: patch-lib_message_mu-contact.hh,v 1.1 2026/01/29 16:41:56 ktnb Exp $

Fix error -30 on NetBSD 11

--- lib/message/mu-contact.hh.orig	2026-01-15 19:59:15.000000000 +0000
+++ lib/message/mu-contact.hh
@@ -184,7 +184,7 @@ struct Contact {
 private:
 	void cleanup_name() { // replace control characters by spaces.
 		for (auto& c: name)
-			if (iscntrl(c))
+			if (iscntrl(static_cast<unsigned char>(c)))
 				c = ' ';
 	}
 
