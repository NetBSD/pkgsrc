$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.4 2015/02/21 20:21:56 tnn Exp $

Fix architecture name.

--- hotspot/make/bsd/makefiles/defs.make.orig	2015-01-26 15:21:52.000000000 +0000
+++ hotspot/make/bsd/makefiles/defs.make
@@ -29,7 +29,7 @@
 SLASH_JAVA ?= /java
 
 # Need PLATFORM (os-arch combo names) for jdk and hotspot, plus libarch name
-ARCH:=$(shell uname -m)
+ARCH:=$(shell uname -m | sed -e 's,x86_64,amd64,' -e 's,.*arm.*,arm,')
 PATH_SEP = :
 ifeq ($(LP64), 1)
   ARCH_DATA_MODEL ?= 64
