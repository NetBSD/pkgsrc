$NetBSD: patch-.._spunk_coll.cc,v 1.1 2011/11/27 19:36:09 joerg Exp $

--- ../spunk/coll.cc.orig	2011-11-27 02:13:15.000000000 +0000
+++ ../spunk/coll.cc
@@ -21,7 +21,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "machine.h"
 #include "check.h"
