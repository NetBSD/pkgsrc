$NetBSD: patch-color.cpp,v 1.2 2013/04/30 22:34:30 joerg Exp $

--- color.cpp.orig	2004-08-13 15:42:29.000000000 +0000
+++ color.cpp
@@ -1,5 +1,7 @@
 #include <math.h>
+#include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <algorithm>
 #include "externs.h"
 #include "misc.h"
