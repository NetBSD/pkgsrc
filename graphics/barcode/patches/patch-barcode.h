$NetBSD: patch-barcode.h,v 1.1 2013/10/06 17:15:35 adam Exp $

Avoid double symbols: define 'streaming' as 'extern'.

--- barcode.h.orig	2013-10-06 07:42:33.000000000 +0000
+++ barcode.h
@@ -123,6 +123,6 @@ extern int Barcode_Version(char *version
 }
 #endif
 
-int streaming;
+extern int streaming;
 
 #endif /* _BARCODE_H_ */
