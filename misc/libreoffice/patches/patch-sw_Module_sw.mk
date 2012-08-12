$NetBSD: patch-sw_Module_sw.mk,v 1.2 2012/08/12 07:09:20 marino Exp $

Disable an unit test crashing with the error message
"No fonts could be found on the system"
in unclear circumstances.

--- sw/Module_sw.mk.orig	2012-08-07 13:32:53.000000000 +0000
+++ sw/Module_sw.mk
@@ -40,11 +40,12 @@ $(eval $(call gb_Module_add_targets,sw,\
     Package_xml \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,sw,\
     CppunitTest_sw_filters_test \
     CppunitTest_sw_macros_test \
-    CppunitTest_sw_swdoc_test \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,sw,\
     JunitTest_sw_complex \
