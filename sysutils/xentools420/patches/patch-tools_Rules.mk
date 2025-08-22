$NetBSD: patch-tools_Rules.mk,v 1.1 2025/08/22 09:00:13 bouyer Exp $

--- tools/Rules.mk.orig	2025-08-04 15:22:34.000000000 +0200
+++ tools/Rules.mk	2025-08-21 19:38:13.321632339 +0200
@@ -83,7 +83,7 @@
 
 # Flags for linking recursive dependencies of Xen libraries in $(1)
 define xenlibs-rpath
-    $(addprefix -Wl$(comma)-rpath-link=$(XEN_ROOT)/tools/libs/,$(call xenlibs-dependencies,$(1)))
+    $(addprefix -Wl$(comma)-rpath-link$(comma)$(XEN_ROOT)/tools/libs/,$(call xenlibs-dependencies,$(1)))
 endef
 
 # Provide a path for each library in $(1)
@@ -118,7 +118,7 @@
  FILENAME_$(1) ?= xen$(1)
  XEN_libxen$(1) = $$(XEN_ROOT)/tools/libs/$(1)
  CFLAGS_libxen$(1) = $$(CFLAGS_xeninclude)
- SHLIB_libxen$(1) = $$(call xenlibs-rpath,$(1)) -Wl,-rpath-link=$$(XEN_libxen$(1))
+ SHLIB_libxen$(1) = $$(call xenlibs-rpath,$(1)) -Wl,-rpath-link,$$(XEN_libxen$(1))
  LDLIBS_libxen$(1) = $$(call xenlibs-ldlibs,$(1))
 endef
 
@@ -220,7 +220,7 @@
 	echo "Description: $(PKG_CONFIG_DESC)"; \
 	echo "Version: $(PKG_CONFIG_VERSION)"; \
 	echo "Cflags: -I\$${includedir}"; \
-	echo "Libs: -L\$${libdir} $(PKG_CONFIG_USELIBS) -l$(PKG_CONFIG_LIB)"; \
+	echo "Libs: -L\$${libdir} -Wl,-rpath,${libdir} $(PKG_CONFIG_USELIBS) -l$(PKG_CONFIG_LIB)"; \
 	echo "Libs.private: $(PKG_CONFIG_LIBSPRIV)"; \
 	echo "Requires.private: $(PKG_CONFIG_REQPRIV)"; \
 	} > $@
@@ -235,7 +235,7 @@
 	echo "Description: $(PKG_CONFIG_DESC)"; \
 	echo "Version: $(PKG_CONFIG_VERSION)"; \
 	echo "Cflags: -I\$${includedir}"; \
-	echo "Libs: -L\$${libdir} -l$(PKG_CONFIG_LIB)"; \
+	echo "Libs: -L\$${libdir} -Wl,-rpath,\$${libdir} -l$(PKG_CONFIG_LIB)"; \
 	echo "Libs.private: $(PKG_CONFIG_LIBSPRIV)"; \
 	echo "Requires.private: $(PKG_CONFIG_REQPRIV)"; \
 	} > $@
