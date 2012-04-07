$NetBSD: patch-src_lib_WPS8.cpp,v 1.4 2012/04/07 15:08:02 wiz Exp $

Fix clang error: expression result unused [-Werror,-Wunused-value]
https://sourceforge.net/tracker/?func=detail&aid=3512534&group_id=176121&atid=875977

--- src/lib/WPS8.cpp.orig	2011-11-10 16:05:28.000000000 +0000
+++ src/lib/WPS8.cpp
@@ -205,8 +205,6 @@ void WPS8Parser::readNotes(std::vector<W
 	if (headerIndexTable.end() == pos)
 		return;
 
-	pos->second.length;
-
 	uint32_t unk1;
 	uint32_t count;
 	uint32_t boff;
