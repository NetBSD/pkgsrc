$NetBSD: patch-src_plan_Nodes_SelectNode.cpp,v 1.1 2011/12/20 13:42:48 wiz Exp $

Add missing header.

--- src/plan/Nodes/SelectNode.cpp.orig	2006-09-29 20:45:18.000000000 +0000
+++ src/plan/Nodes/SelectNode.cpp
@@ -45,6 +45,7 @@
 #include "../../AM/CatalogInstance.h"
 #include "../../Operators/Union.h"
 #include <iostream>
+#include <stdlib.h>
 
 
 // Default
