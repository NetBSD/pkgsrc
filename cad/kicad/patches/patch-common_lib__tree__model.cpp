$NetBSD: patch-common_lib__tree__model.cpp,v 1.1 2020/06/01 03:50:21 mef Exp $

/tmp/cad/kicad/work/kicad-5.1.4/common/lib_tree_model.cpp:78:14: error: 'sort' is not a member of 'std'
         std::sort( sort_buf.begin(), sort_buf.end(),
              ^~~~

--- common/lib_tree_model.cpp.orig	2020-06-01 08:09:39.469102942 +0900
+++ common/lib_tree_model.cpp	2020-06-01 08:10:04.891802170 +0900
@@ -25,6 +25,7 @@
 #include <lib_tree_item.h>
 #include <make_unique.h>
 #include <utility>
+#include <algorithm>
 #include <pgm_base.h>
 #include <kicad_string.h>
 
