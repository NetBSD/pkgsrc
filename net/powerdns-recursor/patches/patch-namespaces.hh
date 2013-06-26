$NetBSD: patch-namespaces.hh,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- namespaces.hh.orig	2010-09-21 16:22:09.000000000 +0000
+++ namespaces.hh
@@ -16,9 +16,7 @@ using boost::tie;
 using boost::shared_ptr;
 using boost::shared_array;
 using boost::scoped_array;
-using boost::tuple;
 using boost::format;
-using boost::make_tuple;
 using boost::optional;
 using boost::any_cast;
 using boost::any;
