$NetBSD: patch-namespaces.hh,v 1.2 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.

--- namespaces.hh.orig	2015-04-21 13:02:57.000000000 +0000
+++ namespaces.hh
@@ -46,9 +46,7 @@ using boost::tie;
 using boost::shared_ptr;
 using boost::shared_array;
 using boost::scoped_array;
-using boost::tuple;
 using boost::format;
-using boost::make_tuple;
 using boost::optional;
 using boost::any_cast;
 using boost::any;
