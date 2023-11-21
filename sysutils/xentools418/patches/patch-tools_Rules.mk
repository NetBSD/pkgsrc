$NetBSD: patch-tools_Rules.mk,v 1.1 2023/11/21 11:37:03 bouyer Exp $

--- tools/Rules.mk.orig	2023-10-11 16:46:01.471180800 +0200
+++ tools/Rules.mk	2023-10-11 16:48:25.511566058 +0200
@@ -90,7 +90,7 @@
 
 # Flags for linking recursive dependencies of Xen libraries in $(1)
 define xenlibs-rpath
-    $(addprefix -Wl$(comma)-rpath-link=$(XEN_ROOT)/tools/libs/,$(call xenlibs-dependencies,$(1)))
+    $(addprefix -Wl$(comma)-rpath-link$(comma)$(XEN_ROOT)/tools/libs/,$(call xenlibs-dependencies,$(1)))
 endef
 
 # Provide a path for each library in $(1)
