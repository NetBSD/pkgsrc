$NetBSD: patch-bgp_bgp__trie.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- bgp/bgp_trie.cc.orig	2009-01-05 18:30:43.000000000 +0000
+++ bgp/bgp_trie.cc
@@ -115,7 +115,7 @@ BgpTrie<A>::erase(const IPNet& net)
 		   net.str().c_str(),
 		   found->attributes()->str().c_str());
 	XLOG_INFO("Pathmap dump follows: \n");
-	for (pmi == _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
+	for (pmi = _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
 	    XLOG_INFO("%s\n\n", pmi->second->str().c_str());
 	}
 	XLOG_FATAL("Exiting\n");
