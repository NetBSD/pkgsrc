$NetBSD: patch-odk_CustomTarget__classes.mk,v 1.2 2014/02/02 07:43:40 ryoon Exp $

* cp(1) of NetBSD 5.2 has no -a option

--- odk/CustomTarget_classes.mk.orig	2013-08-21 11:40:03.000000000 +0000
+++ odk/CustomTarget_classes.mk
@@ -27,7 +27,7 @@ $(call gb_CustomTarget_get_workdir,odk/c
 
 $(call gb_CustomTarget_get_workdir,odk/classes)/java.done: $(call gb_JavaClassSet_get_target,loader)
 	$(call gb_Output_announce,$(subst $(WORKDIR)/,,$@),build,CPY,1)
-	cp -a $(call gb_JavaClassSet_get_classdir,loader)/com $(dir $@) && \
+	cp -r $(call gb_JavaClassSet_get_classdir,loader)/com $(dir $@) && \
 	touch $@
 
 # vim: set noet sw=4 ts=4:
