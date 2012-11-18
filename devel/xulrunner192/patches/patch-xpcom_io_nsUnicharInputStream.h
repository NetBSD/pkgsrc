$NetBSD: patch-xpcom_io_nsUnicharInputStream.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/io/nsUnicharInputStream.h.orig	2012-11-17 15:54:43.000000000 +0000
+++ xpcom/io/nsUnicharInputStream.h
@@ -58,7 +58,7 @@ public:
   static NS_COM nsSimpleUnicharStreamFactory* GetInstance();
 
 private:
-  static const nsSimpleUnicharStreamFactory kInstance;
+  static nsSimpleUnicharStreamFactory kInstance;
 };
 
 #endif // nsUnicharInputStream_h__
