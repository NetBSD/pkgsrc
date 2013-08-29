$NetBSD: patch-layout_generic_nsSelection.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- layout/generic/nsSelection.cpp.orig	2013-08-28 16:44:50.000000000 +0000
+++ layout/generic/nsSelection.cpp
@@ -3057,7 +3057,7 @@ nsIContent*
 nsFrameSelection::IsInSameTable(nsIContent  *aContent1,
                                 nsIContent  *aContent2) const
 {
-  if (!aContent1 || !aContent2) return false;
+  if (!aContent1 || !aContent2) return nsnull;
   
   nsIContent* tableNode1 = GetParentTable(aContent1);
   nsIContent* tableNode2 = GetParentTable(aContent2);
