$NetBSD: patch-eeschema_sim_sim_property.cpp,v 1.2 2024/04/26 16:46:29 tnn Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/sim_property.cpp.orig	2024-03-13 15:55:00.000000000 +0000
+++ eeschema/sim/sim_property.cpp
@@ -30,6 +30,8 @@
 #include <sim/sim_value.h>
 #include <ki_exception.h>
 
+using std::isnan;
+
 
 /**
  *
