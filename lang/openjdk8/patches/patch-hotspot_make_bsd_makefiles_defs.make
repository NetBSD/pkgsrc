$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.5 2017/07/24 12:27:33 wiz Exp $

--- hotspot/make/bsd/makefiles/defs.make.orig	2017-04-27 09:45:08.000000000 +0000
+++ hotspot/make/bsd/makefiles/defs.make
@@ -31,7 +31,7 @@ SLASH_JAVA ?= /java
 # Need PLATFORM (os-arch combo names) for jdk and hotspot, plus libarch name
 # ARCH can be set explicitly in spec.gmk
 ifndef ARCH
-  ARCH := $(shell uname -m)
+  ARCH := $(shell uname -m | sed -e 's,x86_64,amd64,' -e 's,.*arm.*,arm,')
   # Fold little endian PowerPC64 into big-endian (if ARCH is set in
   # hotspot-spec.gmk, this will be done by the configure script).
   ifeq ($(ARCH),ppc64le)
@@ -45,6 +45,10 @@ else
   ARCH_DATA_MODEL ?= 32
 endif
 
+# Extra flags from gnumake's invocation or environment
+CFLAGS += $(EXTRA_CFLAGS)
+LFLAGS += $(EXTRA_LDFLAGS)
+
 # zero
 ifeq ($(findstring true, $(JVM_VARIANT_ZERO) $(JVM_VARIANT_ZEROSHARK)), true)
   ifeq ($(ARCH_DATA_MODEL), 64)
