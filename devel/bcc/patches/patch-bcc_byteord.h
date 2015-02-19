$NetBSD: patch-bcc_byteord.h,v 1.1 2015/02/19 22:25:12 joerg Exp $

--- bcc/byteord.h.orig	2015-02-19 19:39:56.000000000 +0000
+++ bcc/byteord.h
@@ -2,6 +2,9 @@
 
 /* Copyright (C) 1992 Bruce Evans */
 
+#undef BIG_ENDIAN
+#undef LONG_BIG_ENDIAN
+
 #ifdef I8088
 # define BIG_ENDIAN 0
 # define LONG_BIG_ENDIAN 1	/* longs are back to front for Xenix */
