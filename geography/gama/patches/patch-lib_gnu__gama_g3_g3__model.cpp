$NetBSD: patch-lib_gnu__gama_g3_g3__model.cpp,v 1.1 2021/01/24 15:05:05 gdt Exp $

Initialize class member to avoid later uninitialized use.

Sent to upstream maintainer via email 2020-01-24.

--- lib/gnu_gama/g3/g3_model.cpp.orig	2020-11-28 19:50:40.000000000 +0000
+++ lib/gnu_gama/g3/g3_model.cpp
@@ -40,6 +40,8 @@ Model::Model()
   adj            = new Adj;
   adj_input_data = 0;
 
+  A = NULL;
+
   points->set_common_data(this);
   set(&ellipsoid, ellipsoid_wgs84);
 
