$NetBSD: patch-kspread_digest.cc,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- kspread/digest.cc.orig	2011-12-05 18:53:47.000000000 +0000
+++ kspread/digest.cc
@@ -50,7 +50,7 @@ typedef unsigned short sal_uInt16;
 
 #if  SIZEOF_INT == 4
 typedef unsigned int sal_uInt32;
-#elif
+#else
 typedef unsigned long sal_uInt32;
 #endif
 
