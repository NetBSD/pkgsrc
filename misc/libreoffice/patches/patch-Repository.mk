$NetBSD: patch-Repository.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- Repository.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ Repository.mk
@@ -67,13 +67,13 @@ $(eval $(call gb_Helper_register_executa
         svptest \
         svpclient \
         pixelctl ) \
-	$(if $(and $(ENABLE_GTK), $(filter LINUX,$(OS))), tilebench) \
-	$(if $(filter LINUX MACOSX WNT,$(OS)),icontest \
+	$(if $(and $(ENABLE_GTK), $(filter LINUX NETBSD,$(OS))), tilebench) \
+	$(if $(filter LINUX MACOSX WNT NETBSD,$(OS)),icontest \
 	    outdevgrind) \
 	vcldemo \
 	tiledrendering \
     mtfdemo \
-	$(if $(and $(ENABLE_GTK), $(filter LINUX,$(OS))), gtktiledviewer) \
+	$(if $(and $(ENABLE_GTK), $(filter LINUX NETBSD,$(OS))), gtktiledviewer) \
 ))
 
 $(eval $(call gb_Helper_register_executables_for_install,SDK,sdk, \
@@ -581,7 +581,7 @@ $(eval $(call gb_Helper_register_librari
 	i18nlangtag \
 	i18nutil \
 	index_data \
-	$(if $(and $(ENABLE_GTK), $(filter LINUX,$(OS))), libreofficekitgtk) \
+	$(if $(and $(ENABLE_GTK), $(filter LINUX NETBSD,$(OS))), libreofficekitgtk) \
 	localedata_en \
 	localedata_es \
 	localedata_euro \
