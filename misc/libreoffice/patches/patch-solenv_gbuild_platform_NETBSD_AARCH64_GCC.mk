$NetBSD: patch-solenv_gbuild_platform_NETBSD_AARCH64_GCC.mk,v 1.1 2018/11/10 21:35:07 mrg Exp $

add arm64 build support.

--- /dev/null	2018-11-10 16:23:15.111425461 +0000
+++ solenv/gbuild/platform/NETBSD_AARCH64_GCC.mk	2018-11-10 09:48:59.182425793 +0000
@@ -0,0 +1,20 @@
+# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
+#
+# This file is part of the LibreOffice project.
+#
+# This Source Code Form is subject to the terms of the Mozilla Public
+# License, v. 2.0. If a copy of the MPL was not distributed with this
+# file, You can obtain one at http://mozilla.org/MPL/2.0/.
+#
+
+#please make generic modifications to unxgcc.mk
+
+gb_COMPILEROPTFLAGS := -O -g
+
+include $(GBUILDDIR)/platform/unxgcc.mk
+
+NB_ADD_LIBPATH := /usr/pkg/lib:/usr/X11R7/lib
+
+gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$${LD_LIBRARY_PATH:+$$LD_LIBRARY_PATH:}$(WORKDIR)/UnpackedTarball/cppunit/src/cppunit/.libs:$(NB_ADD_LIBPATH)
+
+# vim: set noet sw=4:
