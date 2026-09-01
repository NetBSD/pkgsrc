$NetBSD: patch-nss_coreconf_NetBSD.mk,v 1.6 2026/09/01 18:32:59 tnn Exp $

Match what Linux.mk does for LITTLE_ENDIAN.

--- nss/coreconf/NetBSD.mk.orig	2026-09-01 18:02:54.826000834 +0000
+++ nss/coreconf/NetBSD.mk
@@ -1,3 +1,4 @@
+
 #
 # This Source Code Form is subject to the terms of the Mozilla Public
 # License, v. 2.0. If a copy of the MPL was not distributed with this
@@ -33,6 +34,14 @@ DSO_LDOPTS		= -shared -Wl,-soname,lib$(LIBRARY_NAME)$(
 
 DSO_CFLAGS		= -fPIC -DPIC
 DSO_LDOPTS		= -shared -Wl,-soname,lib$(LIBRARY_NAME)$(LIBRARY_VERSION).$(DLL_SUFFIX)
+
+# Test toolchain for endianness and set LITTLE_ENDIAN variable accordingly
+ENDIANNESS := $(shell echo | $(CC) -dM -E - | grep __BYTE_ORDER__)
+ifeq ($(findstring __ORDER_LITTLE_ENDIAN__,$(ENDIANNESS)),__ORDER_LITTLE_ENDIAN__)
+    LITTLE_ENDIAN := 1
+else
+    LITTLE_ENDIAN := 0
+endif
 
 #
 # The default implementation strategy for NetBSD is pthreads.
