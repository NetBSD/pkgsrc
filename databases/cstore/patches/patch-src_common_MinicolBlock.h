$NetBSD: patch-src_common_MinicolBlock.h,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/common/MinicolBlock.h.orig	2006-04-05 16:33:35.000000000 +0000
+++ src/common/MinicolBlock.h
@@ -5,7 +5,7 @@
 #include "PosBlock.h"
 #include "Constants.h" // for PAGE_SIZE
 #include "BlockWithPos.h"
-#include <list.h>
+#include <list>
 #include "../Operators/MinicolShimOperator.h"
 
 /** An class representing a series of positions and corresponding values from one or
