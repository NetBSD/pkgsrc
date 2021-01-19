$NetBSD: patch-components_detournavigator_offmeshconnectionsmanager.hpp,v 1.1 2021/01/19 12:45:56 nia Exp $

error: 'for_each' is not a member of 'std'

--- components/detournavigator/offmeshconnectionsmanager.hpp.orig	2020-06-08 09:11:24.000000000 +0000
+++ components/detournavigator/offmeshconnectionsmanager.hpp
@@ -17,6 +17,7 @@
 #include <mutex>
 #include <unordered_map>
 #include <unordered_set>
+#include <algorithm>
 #include <vector>
 
 namespace DetourNavigator
