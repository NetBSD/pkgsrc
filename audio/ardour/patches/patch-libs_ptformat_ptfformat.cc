$NetBSD: patch-libs_ptformat_ptfformat.cc,v 1.1 2016/08/27 18:09:16 joerg Exp $

--- libs/ptformat/ptfformat.cc.orig	2016-08-26 19:00:09.397756033 +0000
+++ libs/ptformat/ptfformat.cc
@@ -17,6 +17,7 @@
 #include "ptfformat.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string>
 #include <string.h>
 #include <assert.h>
