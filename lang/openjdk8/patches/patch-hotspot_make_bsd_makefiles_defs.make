$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.4 2016/08/15 19:09:38 ryoon Exp $

--- hotspot/make/bsd/makefiles/defs.make.orig	2016-08-11 05:37:43.000000000 +0000
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
