$NetBSD: patch-bin_version.mk,v 1.1 2015/04/03 01:00:52 tnn Exp $

Patch from FDO git to bring the package up to 8.0.1.

--- bin/version.mk.orig	2015-04-02 23:45:08.000000000 +0000
+++ bin/version.mk
@@ -0,0 +1,17 @@
+#!/usr/bin/make -sf
+# Print the various Mesa version fields. This is mostly used to add the
+# version to configure.
+
+# This reflects that this script is usually called from the toplevel
+TOP = .
+
+include $(TOP)/configs/default
+
+version:
+	@echo $(MESA_VERSION)
+major:
+	@echo $(MESA_MAJOR)
+minor:
+	@echo $(MESA_MINOR)
+tiny:
+	@echo $(MESA_TINY)
