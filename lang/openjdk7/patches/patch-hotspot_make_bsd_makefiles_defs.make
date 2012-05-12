$NetBSD: patch-hotspot_make_bsd_makefiles_defs.make,v 1.1 2012/05/12 21:01:47 marino Exp $

--- hotspot/make/bsd/makefiles/defs.make.orig	2012-05-12 16:55:32.316262000 +0000
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
