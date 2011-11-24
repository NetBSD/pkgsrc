$NetBSD: patch-src_classes_visioExporter.cc,v 1.1 2011/11/24 13:53:06 joerg Exp $

--- src/classes/visioExporter.cc.orig	2011-11-24 01:07:35.000000000 +0000
+++ src/classes/visioExporter.cc
@@ -1,5 +1,6 @@
 #include "visioExporter.h"
-
+#include <stdlib.h>
+#include <string.h>
 
 visioExporter::visioExporter(char *what_file, nodes *what_nodes) {
   filename = strdup(what_file);
