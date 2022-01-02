$NetBSD: patch-common_lib__tree__model.cpp,v 1.2 2022/01/02 19:10:03 tnn Exp $

/tmp/cad/kicad/work/kicad-5.1.4/common/lib_tree_model.cpp:78:14: error: 'sort' is not a member of 'std'
         std::sort( sort_buf.begin(), sort_buf.end(),

--- common/lib_tree_model.cpp.orig	2021-12-22 13:32:19.000000000 +0000
+++ common/lib_tree_model.cpp
@@ -25,6 +25,7 @@
 #include <eda_pattern_match.h>
 #include <lib_tree_item.h>
 #include <utility>
+#include <algorithm>
 #include <pgm_base.h>
 #include <string_utils.h>
 
