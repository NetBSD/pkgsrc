$NetBSD: patch-src_classes_psExporter.cc,v 1.1 2011/11/24 13:53:06 joerg Exp $

--- src/classes/psExporter.cc.orig	2011-11-24 01:08:36.000000000 +0000
+++ src/classes/psExporter.cc
@@ -1,5 +1,6 @@
 #include "psExporter.h"
-
+#include <stdlib.h>
+#include <string.h>
 
 psExporter::psExporter(char *what_file, nodes *what_nodes) {
    filename = strdup(what_file);
