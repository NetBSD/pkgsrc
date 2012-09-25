$NetBSD: patch-source_Public-headers_TECkit__Common.h,v 1.1 2012/09/25 11:18:27 sbd Exp $

--- source/Public-headers/TECkit_Common.h.orig	2012-09-25 11:11:23.054232507 +0000
+++ source/Public-headers/TECkit_Common.h
@@ -33,7 +33,10 @@ History:
 typedef unsigned char			UInt8;
 typedef unsigned short			UInt16;
 typedef unsigned int			UInt32;	/* NB: assumes int is 4 bytes */
+/* zconf.h defines 'Byte' */
+#ifndef ZCONF_H	
 typedef UInt8					Byte;
+#endif
 typedef Byte*					BytePtr;
 typedef UInt16					UniChar;
 
