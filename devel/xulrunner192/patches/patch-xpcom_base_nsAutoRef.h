$NetBSD: patch-xpcom_base_nsAutoRef.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/base/nsAutoRef.h.orig	2012-11-17 16:43:33.000000000 +0000
+++ xpcom/base/nsAutoRef.h
@@ -323,7 +323,7 @@ protected:
     void SafeAddRef()
     {
         if (this->HaveResource())
-            AddRef(this->get());
+            this->AddRef(this->get());
     }
 };
 
@@ -690,7 +690,7 @@ protected:
     void SafeRelease()
     {
         if (this->HaveResource())
-            Release(this->get());
+            this->Release(this->get());
     }
 };
 
