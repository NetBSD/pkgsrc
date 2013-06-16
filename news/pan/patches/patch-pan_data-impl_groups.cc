$NetBSD: patch-pan_data-impl_groups.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/data-impl/groups.cc.orig	2013-06-16 10:45:37.000000000 +0000
+++ pan/data-impl/groups.cc
@@ -81,8 +81,6 @@ namespace
   }
 }
 
-#include <ext/algorithm>
-
 void
 DataImpl :: load_newsrc (const Quark       & server,
                          LineReader        * in,
