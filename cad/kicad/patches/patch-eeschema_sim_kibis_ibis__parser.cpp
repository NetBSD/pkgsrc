$NetBSD: patch-eeschema_sim_kibis_ibis__parser.cpp,v 1.2 2026/09/29 16:11:56 bouyer Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/kibis/ibis_parser.cpp.orig	2026-04-15 15:36:56.000000000 +0000
+++ eeschema/sim/kibis/ibis_parser.cpp
@@ -38,6 +38,8 @@
 #include <locale_io.h> // KiCad header
 #include <wx/log.h>
 
+using std::isnan;
+
 // _() is used here to mark translatable strings in IBIS_REPORTER::Report()
 // However, currently non ASCII7 chars are nor correctly handled when printing messages
 // So we disable translations
