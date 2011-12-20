$NetBSD: patch-src_Wrappers_PosArrayBlock.h,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Wrappers/PosArrayBlock.h.orig	2006-09-19 21:47:50.000000000 +0000
+++ src/Wrappers/PosArrayBlock.h
@@ -4,7 +4,7 @@
 #include "../common/PosBlock.h"
 #include "../common/UnexpectedException.h"
 #include "../common/UnimplementedException.h"
-#include <iostream.h>
+#include <iostream>
 
 class PosArrayBlock : public PosBlock
 {
