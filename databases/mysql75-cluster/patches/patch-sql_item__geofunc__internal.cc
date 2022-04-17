$NetBSD: patch-sql_item__geofunc__internal.cc,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- sql/item_geofunc_internal.cc.orig	2021-09-14 09:08:08.000000000 +0000
+++ sql/item_geofunc_internal.cc
@@ -41,11 +41,6 @@ void handle_gis_exception(const char *fu
   {
     my_error(ER_BOOST_GEOMETRY_TURN_INFO_EXCEPTION, MYF(0), funcname);
   }
-  catch (const boost::geometry::detail::self_get_turn_points::self_ip_exception &)
-  {
-    my_error(ER_BOOST_GEOMETRY_SELF_INTERSECTION_POINT_EXCEPTION, MYF(0),
-             funcname);
-  }
   catch (const boost::geometry::empty_input_exception &)
   {
     my_error(ER_BOOST_GEOMETRY_EMPTY_INPUT_EXCEPTION, MYF(0), funcname);
