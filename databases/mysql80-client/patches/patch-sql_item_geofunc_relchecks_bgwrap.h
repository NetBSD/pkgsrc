$NetBSD: patch-sql_item_geofunc_relchecks_bgwrap.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

<algorithm> is needed to define std::for_each() required by the boost 1.73
headers

--- sql/item_geofunc_relchecks_bgwrap.h.orig	2021-05-09 10:15:24.903436550 +0000
+++ sql/item_geofunc_relchecks_bgwrap.h
@@ -39,6 +39,7 @@
 #include <set>
 #include <string>  // Boost expects std::string to be already present.
 #include <vector>
+#include <algorithm>
 
 #include <boost/geometry/algorithms/crosses.hpp>
 #include <boost/geometry/algorithms/intersects.hpp>
