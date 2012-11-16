$NetBSD: patch-spunk_coll.cc,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/coll.cc.orig	1996-11-30 00:40:58.000000000 +0000
+++ spunk/coll.cc
@@ -21,7 +21,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "machine.h"
 #include "check.h"
