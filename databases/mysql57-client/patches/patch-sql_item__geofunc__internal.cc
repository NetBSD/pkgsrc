$NetBSD: patch-sql_item__geofunc__internal.cc,v 1.1 2017/09/13 17:34:41 adam Exp $

Do not try to catch non-existent exception.

--- sql/item_geofunc_internal.cc.orig	2017-09-13 12:53:40.000000000 +0000
+++ sql/item_geofunc_internal.cc
@@ -34,11 +34,6 @@ void handle_gis_exception(const char *fu
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
