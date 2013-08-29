$NetBSD: patch-accessible_src_base_nsDocAccessible.h,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- accessible/src/base/nsDocAccessible.h.orig	2013-08-28 19:31:28.000000000 +0000
+++ accessible/src/base/nsDocAccessible.h
@@ -262,7 +262,7 @@ public:
     while (acc && !acc->IsPrimaryForNode())
       acc = acc->Parent();
 
-    return acc ? mNodeToAccessibleMap.Get(acc->GetNode()) : false;
+    return acc ? mNodeToAccessibleMap.Get(acc->GetNode()) != nsnull : false;
   }
 
   /**
