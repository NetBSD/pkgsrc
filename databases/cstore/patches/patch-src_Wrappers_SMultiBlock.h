$NetBSD: patch-src_Wrappers_SMultiBlock.h,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Wrappers/SMultiBlock.h.orig	2006-03-12 22:03:51.000000000 +0000
+++ src/Wrappers/SMultiBlock.h
@@ -36,7 +36,7 @@
 #include "../common/Block.h"
 #include "../common/SBlock.h"
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
 
 class SMultiBlock : public SBlock
 {
