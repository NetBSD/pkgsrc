$NetBSD: patch-src_utility.h,v 1.1 2015/11/04 12:32:10 joerg Exp $

--- src/utility.h.orig	2015-11-03 11:44:20.000000000 +0000
+++ src/utility.h
@@ -88,7 +88,7 @@ bool from_string(const Glib::ustring &sr
 	std::istringstream s(src);
 	// return s >> dest != 0;
 
-	bool state = s >> dest != 0;
+	bool state(s >> dest);
 
 	if(!state)
 		se_debug_message(SE_DEBUG_UTILITY, "string:'%s'failed.", src.c_str());
