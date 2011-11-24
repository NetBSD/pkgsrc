$NetBSD: patch-src_classes_nodes.cc,v 1.1 2011/11/24 13:53:06 joerg Exp $

--- src/classes/nodes.cc.orig	2011-11-24 01:07:04.000000000 +0000
+++ src/classes/nodes.cc
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "nodes.h"
 
 
