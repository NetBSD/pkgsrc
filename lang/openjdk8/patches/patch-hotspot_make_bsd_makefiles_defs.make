$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.3 2016/05/06 13:37:01 ryoon Exp $

--- hotspot/make/bsd/makefiles/defs.make.orig	2016-05-06 12:11:25.000000000 +0000
+++ hotspot/make/bsd/makefiles/defs.make
@@ -31,7 +31,7 @@ SLASH_JAVA ?= /java
 # Need PLATFORM (os-arch combo names) for jdk and hotspot, plus libarch name
 # ARCH can be set explicitly in spec.gmk
 ifndef ARCH
-  ARCH := $(shell uname -m)
+  ARCH := $(shell uname -m | sed -e 's,x86_64,amd64,' -e 's,.*arm.*,arm,')
 endif
 PATH_SEP = :
 ifeq ($(LP64), 1)
