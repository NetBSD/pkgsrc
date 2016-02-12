$NetBSD: patch-include_mdds_flat__segment__tree.hpp,v 1.1 2016/02/12 13:34:45 wiz Exp $

https://gerrit.libreoffice.org/gitweb?p=core.git;a=commit;h=bead58cb4042ac42dee890e2f21ab7ea81136e54

--- include/mdds/flat_segment_tree.hpp.orig	2015-06-11 23:53:55.000000000 +0000
+++ include/mdds/flat_segment_tree.hpp
@@ -32,7 +32,6 @@
 #include <sstream>
 #include <utility>
 #include <cassert>
-#include <limits>
 
 #include "mdds/node.hpp"
 #include "mdds/flat_segment_tree_itr.hpp"
