$NetBSD: patch-editor_libeditor_html_nsHTMLEditor.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- editor/libeditor/html/nsHTMLEditor.cpp.orig	2013-08-28 16:32:03.000000000 +0000
+++ editor/libeditor/html/nsHTMLEditor.cpp
@@ -935,7 +935,7 @@ nsHTMLEditor::GetBlockNodeParent(nsIDOMN
   if (!aNode)
   {
     NS_NOTREACHED("null node passed to GetBlockNodeParent()");
-    return false;
+    return nsnull;
   }
 
   nsCOMPtr<nsIDOMNode> p;
@@ -5838,7 +5838,7 @@ nsHTMLEditor::IsActiveInDOMWindow()
 nsIContent*
 nsHTMLEditor::GetActiveEditingHost()
 {
-  NS_ENSURE_TRUE(mDocWeak, false);
+  NS_ENSURE_TRUE(mDocWeak, nsnull);
 
   nsCOMPtr<nsIDocument> doc = do_QueryReferent(mDocWeak);
   NS_ENSURE_TRUE(doc, nsnull);
