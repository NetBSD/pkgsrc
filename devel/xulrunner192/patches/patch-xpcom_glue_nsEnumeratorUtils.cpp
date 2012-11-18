$NetBSD: patch-xpcom_glue_nsEnumeratorUtils.cpp,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/glue/nsEnumeratorUtils.cpp.orig	2012-11-17 15:47:22.000000000 +0000
+++ xpcom/glue/nsEnumeratorUtils.cpp
@@ -67,7 +67,7 @@ public:
     }
 
 private:
-    static const EmptyEnumeratorImpl kInstance;
+    static EmptyEnumeratorImpl kInstance;
 };
 
 // nsISupports interface
@@ -112,7 +112,7 @@ NS_IMETHODIMP EmptyEnumeratorImpl::GetNe
     return NS_ERROR_UNEXPECTED;
 }
 
-const EmptyEnumeratorImpl EmptyEnumeratorImpl::kInstance;
+EmptyEnumeratorImpl EmptyEnumeratorImpl::kInstance;
 
 nsresult
 NS_NewEmptyEnumerator(nsISimpleEnumerator** aResult)
