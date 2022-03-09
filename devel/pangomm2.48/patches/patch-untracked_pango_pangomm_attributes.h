$NetBSD: patch-untracked_pango_pangomm_attributes.h,v 1.1 2022/03/09 14:14:11 ryoon Exp $

* Fix for pangp-1.50.5.

--- untracked/pango/pangomm/attributes.h.orig	2021-05-21 11:14:18.119759300 +0000
+++ untracked/pango/pangomm/attributes.h
@@ -30,6 +30,7 @@
 #include <pangomm/color.h>
 #include <pangomm/fontdescription.h>
 #include <pango/pango-attributes.h>
+#include <pango/pango-markup.h>
 
 
 namespace Pango
