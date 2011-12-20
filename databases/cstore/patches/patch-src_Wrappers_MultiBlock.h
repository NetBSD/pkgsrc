$NetBSD: patch-src_Wrappers_MultiBlock.h,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Wrappers/MultiBlock.h.orig	2006-08-22 22:29:07.000000000 +0000
+++ src/Wrappers/MultiBlock.h
@@ -36,7 +36,7 @@
 #include "../common/Block.h"
 #include "Type2Block.h"
 #include "CodingException.h"
-#include <iostream.h>
+#include <iostream>
 
 class MultiBlock : public Block
 {
