$NetBSD: patch-libcurvecpr_include_curvecpr_messager.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/include/curvecpr/messager.h.orig	2019-12-22 17:55:13.590078135 +0000
+++ libcurvecpr/include/curvecpr/messager.h
@@ -1,13 +1,12 @@
 #ifndef __CURVECPR_MESSAGER_H
 #define __CURVECPR_MESSAGER_H
 
+#include "bytes.h"
 #include "block.h"
 #include "chicago.h"
 
 #include <string.h>
 
-#include <sodium/crypto_uint32.h>
-
 struct curvecpr_messager;
 
 struct curvecpr_messager_ops {
