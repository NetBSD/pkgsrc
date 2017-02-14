$NetBSD: patch-guetzli_output__image.cc,v 1.1 2017/02/14 21:28:09 joerg Exp $

--- guetzli/output_image.cc.orig	2017-02-09 17:17:16.588389327 +0000
+++ guetzli/output_image.cc
@@ -19,6 +19,7 @@
 #include <algorithm>
 #include <assert.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <cmath>
 
