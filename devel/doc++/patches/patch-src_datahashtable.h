$NetBSD: patch-src_datahashtable.h,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/datahashtable.h.orig	2011-11-25 17:20:17.000000000 +0000
+++ src/datahashtable.h
@@ -26,11 +26,13 @@
 #define _DATAHASHTABLE_H
 
 #include <assert.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 
 #include "McDArray.h"
 
+using namespace std;
+
 /* This should be a private subclass of #DataHashTable#. However, since cfront
    is not able to compile this constrution, we had move the class to global
    scope.
