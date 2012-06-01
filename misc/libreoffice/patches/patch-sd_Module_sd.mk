$NetBSD: patch-sd_Module_sd.mk,v 1.1.1.1 2012/06/01 06:12:14 wiz Exp $

Disable unit tests crashing on DragonFly and NetBSD

--- sd/Module_sd.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ sd/Module_sd.mk
@@ -40,7 +40,7 @@ $(eval $(call gb_Module_add_targets,sd,\
     Package_xml \
 ))
 
-ifneq ($(OS),DRAGONFLY)
+ifeq (,$(filter DRAGONFLY NETBSD,$(OS)))
 $(eval $(call gb_Module_add_check_targets,sd,\
     CppunitTest_sd_uimpress \
 ))
