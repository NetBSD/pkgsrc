$NetBSD: patch-eeschema_sim_sim_property.cpp,v 1.1 2023/06/06 10:20:58 bouyer Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/sim_property.cpp.orig	2023-06-03 11:54:31.739102496 +0200
+++ eeschema/sim/sim_property.cpp	2023-06-03 11:55:13.347928053 +0200
@@ -30,6 +30,8 @@
 #include <sim/sim_value.h>
 #include <ki_exception.h>
 
+using std::isnan;
+
 
 SIM_PROPERTY::SIM_PROPERTY( SIM_MODEL& aModel, int aParamIndex ) :
         m_model( aModel ),
