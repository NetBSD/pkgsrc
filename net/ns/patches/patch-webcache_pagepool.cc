$NetBSD: patch-webcache_pagepool.cc,v 1.1 2014/02/01 08:04:04 markd Exp $

Fix invalid conversion from 'void*' to 'char*'

--- webcache/pagepool.cc.orig	2011-10-06 00:27:14.000000000 +0000
+++ webcache/pagepool.cc
@@ -658,7 +658,7 @@ int ClientPagePool::command(int argc, co
 			for (he = Tcl_FirstHashEntry(namemap_, &hs); 
 			     he != NULL;
 			     he = Tcl_NextHashEntry(&hs)) {
-				char* retVal = Tcl_GetHashKey(namemap_, he);
+				char* retVal = (char *) Tcl_GetHashKey(namemap_, he);
 				// Convert name to a PageID
 				PageID t1;
 				ClientPage::split_name (retVal, t1);
