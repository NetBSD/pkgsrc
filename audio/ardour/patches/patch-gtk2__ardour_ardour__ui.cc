$NetBSD: patch-gtk2__ardour_ardour__ui.cc,v 1.4 2024/02/10 10:41:43 wiz Exp $

Fix build with libxml2 2.12.

--- gtk2_ardour/ardour_ui.cc.orig	2024-02-10 10:40:02.977463986 +0000
+++ gtk2_ardour/ardour_ui.cc
@@ -264,7 +264,7 @@ libxml_generic_error_func (void* /* pars
 
 static void
 libxml_structured_error_func (void* /* parsing_context*/,
-                              xmlErrorPtr err)
+                              const xmlError *err)
 {
 	string msg;
 
