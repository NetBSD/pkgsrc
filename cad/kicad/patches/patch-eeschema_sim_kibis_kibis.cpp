$NetBSD: patch-eeschema_sim_kibis_kibis.cpp,v 1.1 2023/02/13 07:59:01 tnn Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/kibis/kibis.cpp.orig	2023-02-11 16:03:39.000000000 +0000
+++ eeschema/sim/kibis/kibis.cpp
@@ -34,6 +34,7 @@
 #include <sstream>
 #include <sim/spice_simulator.h>
 
+using std::isnan;
 
 // _() is used here to mark translatable strings in IBIS_REPORTER::Report()
 // However, currently non ASCII7 chars are nor correctly handled when printing messages
