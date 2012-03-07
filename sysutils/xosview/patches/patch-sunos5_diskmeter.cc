$NetBSD: patch-sunos5_diskmeter.cc,v 1.1 2012/03/07 16:14:40 hans Exp $

--- sunos5/diskmeter.cc.orig	1999-11-07 00:12:34.000000000 +0100
+++ sunos5/diskmeter.cc	2012-03-07 17:12:17.363721614 +0100
@@ -7,7 +7,7 @@
 
 #include "diskmeter.h"
 #include "xosview.h"
-#include <fstream.h>
+#include <fstream>
 #include <stdlib.h>
 
 
