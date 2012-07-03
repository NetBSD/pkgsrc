$NetBSD: patch-libxipc_finder.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxipc/finder.cc.orig	2009-01-05 18:30:55.000000000 +0000
+++ libxipc/finder.cc
@@ -93,7 +93,7 @@ public:
 	    for (i = _resolutions.begin(); i != _resolutions.end(); ++i) {
 		debug_msg("Have \"%s\"\n", i->first.c_str());
 	    }
-	    return false;
+	    return 0;
 	}
 	return &i->second;
     }
