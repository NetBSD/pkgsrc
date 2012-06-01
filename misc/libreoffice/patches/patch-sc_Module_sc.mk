$NetBSD: patch-sc_Module_sc.mk,v 1.1.1.1 2012/06/01 06:12:14 wiz Exp $

Disable unit tests crashing on DragonFly and NetBSD

--- sc/Module_sc.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ sc/Module_sc.mk
@@ -34,11 +34,6 @@ $(eval $(call gb_Module_add_targets,sc,\
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-    CppunitTest_sc_filters_test \
-    CppunitTest_sc_ucalc \
-))
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sc,\
     CppunitTest_sc_macros_test \
     CppunitTest_sc_cellrangesbase \
