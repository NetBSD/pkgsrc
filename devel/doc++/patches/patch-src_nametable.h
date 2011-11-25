$NetBSD: patch-src_nametable.h,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/nametable.h.orig	2011-11-25 17:20:06.000000000 +0000
+++ src/nametable.h
@@ -25,7 +25,7 @@
 #define	_NAME_TABLE_H
 
 #include <assert.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "datahashtable.h"
 
