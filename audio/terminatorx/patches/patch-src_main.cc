$NetBSD: patch-src_main.cc,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/main.cc.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/main.cc
@@ -27,7 +27,7 @@
 
 #include <stdio.h>
 #include "tX_mastergui.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 #include <stdio.h>
 #ifndef WIN32
