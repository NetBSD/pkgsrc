$NetBSD: patch-src_level_Landslip.cpp,v 1.1 2011/11/24 14:08:48 joerg Exp $

--- src/level/Landslip.cpp.orig	2011-11-24 00:52:41.000000000 +0000
+++ src/level/Landslip.cpp
@@ -11,6 +11,8 @@
 #include "Rules.h"
 #include "minmax.h"
 
+#include <string.h>
+
 //-----------------------------------------------------------------
     Landslip::Landslip(const ModelList &models)
 : m_models(models)
