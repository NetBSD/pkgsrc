$NetBSD: patch-courier_cdfilters.C,v 1.1 2011/11/26 17:14:42 joerg Exp $

--- courier/cdfilters.C.orig	2011-11-26 15:35:04.000000000 +0000
+++ courier/cdfilters.C
@@ -13,6 +13,7 @@
 #include	<unistd.h>
 #endif
 #include	<stdlib.h>
+#include	<string.h>
 #include	<errno.h>
 #include	<ctype.h>
 
