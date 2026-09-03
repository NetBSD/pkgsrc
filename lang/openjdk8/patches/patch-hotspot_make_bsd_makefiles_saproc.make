$NetBSD: patch-hotspot_make_bsd_makefiles_saproc.make,v 1.4 2026/09/03 17:12:42 jperkin Exp $

--- hotspot/make/bsd/makefiles/saproc.make.orig	2026-07-23 23:26:52.000000000 +0000
+++ hotspot/make/bsd/makefiles/saproc.make
@@ -114,7 +114,6 @@ ifneq ($(filter-out ia64 arm zero,$(SRCA
 endif
 endif
 
-
 ifneq ($(OS_VENDOR), Darwin)
   SA_LFLAGS = $(MAPFLAG:FILENAME=$(SAMAPFILE))
 else
@@ -123,6 +122,8 @@ else
 endif
 SA_LFLAGS += $(LDFLAGS_HASH_STYLE) $(EXTRA_LDFLAGS)
 
+SA_LFLAGS += $(EXTRA_LDFLAGS)
+
 BOOT_JAVA_INCLUDES = -I$(BOOT_JAVA_HOME)/include \
   -I$(BOOT_JAVA_HOME)/include/$(shell uname -s | tr "[:upper:]" "[:lower:]")
 
