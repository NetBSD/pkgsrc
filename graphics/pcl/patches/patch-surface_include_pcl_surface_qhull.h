$NetBSD: patch-surface_include_pcl_surface_qhull.h,v 1.1 2021/05/03 06:25:11 thor Exp $

Support current qhull (from PR 4540).

--- surface/include/pcl/surface/qhull.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ surface/include/pcl/surface/qhull.h
@@ -49,14 +49,14 @@
 extern "C"
 {
 #ifdef HAVE_QHULL_2011
-#  include "libqhull/libqhull.h"
-#  include "libqhull/mem.h"
-#  include "libqhull/qset.h"
-#  include "libqhull/geom.h"
-#  include "libqhull/merge.h"
-#  include "libqhull/poly.h"
-#  include "libqhull/io.h"
-#  include "libqhull/stat.h"
+#  include "libqhull_r/libqhull_r.h"
+#  include "libqhull_r/mem_r.h"
+#  include "libqhull_r/qset_r.h"
+#  include "libqhull_r/geom_r.h"
+#  include "libqhull_r/merge_r.h"
+#  include "libqhull_r/poly_r.h"
+#  include "libqhull_r/io_r.h"
+#  include "libqhull_r/stat_r.h"
 #else
 #  include "qhull/qhull.h"
 #  include "qhull/mem.h"
