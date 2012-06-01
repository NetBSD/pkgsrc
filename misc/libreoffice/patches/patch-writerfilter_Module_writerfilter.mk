$NetBSD: patch-writerfilter_Module_writerfilter.mk,v 1.1.1.1 2012/06/01 06:12:14 wiz Exp $

Disable unit tests crashing on NetBSD

--- writerfilter/Module_writerfilter.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ writerfilter/Module_writerfilter.mk
@@ -37,10 +37,12 @@ $(eval $(call gb_Module_add_targets,writ
     Package_writerfilter_generated \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,writerfilter,\
     CppunitTest_writerfilter_doctok \
     CppunitTest_writerfilter_rtftok \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,writerfilter,\
     JunitTest_writerfilter_complex \
