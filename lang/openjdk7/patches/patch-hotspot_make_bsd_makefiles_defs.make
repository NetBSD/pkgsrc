$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.3 2013/06/15 09:31:05 jperkin Exp $

64-bit support.

--- hotspot/make/bsd/makefiles/defs.make.orig	2013-05-29 03:57:57.000000000 +0000
+++ hotspot/make/bsd/makefiles/defs.make
@@ -30,6 +30,10 @@ SLASH_JAVA ?= /java
 
 # Need PLATFORM (os-arch combo names) for jdk and hotspot, plus libarch name
 ARCH:=$(shell uname -m)
+ifeq ($(ARCH),x86_64)
+  ARCH=amd64
+endif
+
 PATH_SEP = :
 ifeq ($(LP64), 1)
   ARCH_DATA_MODEL ?= 64
