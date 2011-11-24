$NetBSD: patch-src_classes_optFileReader.cc,v 1.1 2011/11/24 13:53:06 joerg Exp $

--- src/classes/optFileReader.cc.orig	2011-11-24 01:08:20.000000000 +0000
+++ src/classes/optFileReader.cc
@@ -1,4 +1,5 @@
 #include "optFileReader.h"
+#include <stdlib.h>
 #include <string.h>
 #include <gtk/gtk.h>
 #include "../interface.h"
