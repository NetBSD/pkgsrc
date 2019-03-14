$NetBSD: patch-simgear_nasal_cppbind_NasalHash.hxx,v 1.1 2019/03/14 18:13:18 nia Exp $

Uses enable_if - don't rely on indirect inclusion.

--- simgear/nasal/cppbind/NasalHash.hxx.orig	2019-01-29 13:17:36.000000000 +0000
+++ simgear/nasal/cppbind/NasalHash.hxx
@@ -23,6 +23,7 @@
 #include "to_nasal.hxx"
 
 #include <simgear/structure/map.hxx>
+#include <boost/core/enable_if.hpp>
 #include <boost/iterator/iterator_facade.hpp>
 
 namespace nasal
