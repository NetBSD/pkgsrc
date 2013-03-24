$NetBSD: patch-APIModules_QTSSAdminModule_AdminElementNode.cpp,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- APIModules/QTSSAdminModule/AdminElementNode.cpp.orig	2003-08-15 23:52:42.000000000 +0000
+++ APIModules/QTSSAdminModule/AdminElementNode.cpp
@@ -883,7 +883,7 @@ inline  SInt32 ElementNode::ResolveSPLKe
     if (fElementMap != NULL && keyPtr != NULL && keyPtr->Len > 0) 
     {   osrefptr = fElementMap->Resolve(keyPtr);
         if (osrefptr != NULL) 
-            index = (SInt32) osrefptr->GetObject();
+            index = (SInt32)(intptr_t) osrefptr->GetObject();
     }
 
     return index;   
