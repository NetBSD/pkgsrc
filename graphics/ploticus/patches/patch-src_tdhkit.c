$NetBSD: patch-src_tdhkit.c,v 1.1 2013/06/30 15:13:09 ryoon Exp $

* Include stdlib.h for putenv(3).

--- src/tdhkit.c.orig	2008-01-11 16:48:13.000000000 +0000
+++ src/tdhkit.c
@@ -13,6 +13,7 @@
 
    
 #include "tdhkit.h"
+#include <stdlib.h>
 #include <ctype.h>
 
 extern int DT_setdateparms();
