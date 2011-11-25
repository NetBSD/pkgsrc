$NetBSD: patch-bb_gob.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- bb/gob.h.orig	2011-11-25 15:17:06.000000000 +0000
+++ bb/gob.h
@@ -7,8 +7,10 @@
 #define BBGOB_h
 
 
-#include <list.h>
-#include <vector.h>
+#include <list>
+#include <vector>
+
+using namespace std;
 
 #include "view.h"
 #include "bb.h"
