$NetBSD: patch-eeschema_sim_kibis_ibis__parser.cpp,v 1.1 2023/02/13 07:59:01 tnn Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/kibis/ibis_parser.cpp.orig	2023-02-11 16:03:39.000000000 +0000
+++ eeschema/sim/kibis/ibis_parser.cpp
@@ -37,6 +37,8 @@
 #include <iterator>
 #include <locale_io.h> // KiCad header
 
+using std::isnan;
+
 // _() is used here to mark translatable strings in IBIS_REPORTER::Report()
 // However, currently non ASCII7 chars are nor correctly handled when printing messages
 // So we disable translations
