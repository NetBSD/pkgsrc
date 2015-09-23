$NetBSD: patch-odk_CustomTarget__javadoc.mk,v 1.1 2015/09/23 20:48:44 joerg Exp $

--- odk/CustomTarget_javadoc.mk.orig	2015-08-14 13:38:24.000000000 +0000
+++ odk/CustomTarget_javadoc.mk
@@ -32,7 +32,7 @@ $(call gb_CustomTarget_get_workdir,odk/d
 		$(call gb_Jar_get_target,ridl)
 	$(call gb_Output_announce,$(subst $(WORKDIR)/,,$@),$(true),JDC,1)
 	$(call gb_Helper_abbreviate_dirs,\
-		$(JAVADOC) -J-Xmx120m -use -splitindex \
+		$(JAVADOC) -J-Xmx120m -use -splitindex -Xdoclint:none \
 		-windowtitle "Java UNO Runtime Reference" \
 		-header "$(PRODUCTNAME) $(PRODUCTVERSION) SDK Java API Reference"\
 		-tag attention:a:"Attention:" \
