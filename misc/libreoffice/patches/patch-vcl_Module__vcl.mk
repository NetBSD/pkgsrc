$NetBSD: patch-vcl_Module__vcl.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Module_vcl.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Module_vcl.mk
@@ -27,7 +27,7 @@ $(eval $(call gb_Module_add_targets,vcl,
         StaticLibrary_vclmain \
 		$(if $(ENABLE_HEADLESS),, \
 			Executable_ui-previewer) \
-		$(if $(filter LINUX MACOSX WNT,$(OS)), \
+		$(if $(filter LINUX MACOSX WNT NETBSD,$(OS)), \
 			Executable_outdevgrind \
 			$(if $(ENABLE_HEADLESS),, \
 				Executable_vcldemo \
