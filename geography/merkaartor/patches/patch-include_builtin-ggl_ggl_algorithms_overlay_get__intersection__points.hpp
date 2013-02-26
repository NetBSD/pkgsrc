$NetBSD: patch-include_builtin-ggl_ggl_algorithms_overlay_get__intersection__points.hpp,v 1.1 2013/02/26 11:15:19 joerg Exp $

--- include/builtin-ggl/ggl/algorithms/overlay/get_intersection_points.hpp.orig	2011-02-10 12:00:35.000000000 +0000
+++ include/builtin-ggl/ggl/algorithms/overlay/get_intersection_points.hpp
@@ -94,8 +94,8 @@ struct relate
                     >
             >::relate(s1, s2);
 
-        ip_type& is = result.get<0>();
-        policies::relate::direction_type & dir = result.get<1>();
+        ip_type& is = get<0>(result);
+        policies::relate::direction_type & dir = get<1>(result);
 
         for (int i = 0; i < is.count; i++)
         {
