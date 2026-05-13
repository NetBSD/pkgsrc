$NetBSD: patch-lib_message_mu-labels.cc,v 1.1 2026/05/13 18:34:47 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/message/mu-labels.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/message/mu-labels.cc
@@ -50,11 +50,11 @@ Mu::Labels::validate_label(const std::string &label)
 		if (g_unichar_isalnum(uc))
 			continue; // alphanum is okay
 
-		if (::iscntrl(uc))
+		if (::iscntrl(static_cast<unsigned char>(uc)))
 			return Err(Error{Error::Code::InvalidArgument,
 					"control character {} not allowed in label",
 					static_cast<int>(uc)});
-		if (::isblank(uc))
+		if (::isblank(static_cast<unsigned char>(uc)))
 			return Err(Error{Error::Code::InvalidArgument,
 					"blank character {} not allowed in label",
 					static_cast<int>(uc)});
