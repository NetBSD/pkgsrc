$NetBSD: patch-xpcom_io_nsUnicharInputStream.cpp,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/io/nsUnicharInputStream.cpp.orig	2012-11-17 15:54:14.000000000 +0000
+++ xpcom/io/nsUnicharInputStream.cpp
@@ -463,5 +463,5 @@ nsSimpleUnicharStreamFactory::GetInstanc
   return const_cast<nsSimpleUnicharStreamFactory*>(&kInstance);
 }
 
-const nsSimpleUnicharStreamFactory
+nsSimpleUnicharStreamFactory
 nsSimpleUnicharStreamFactory::kInstance;
