$NetBSD: patch-hotspot_make_bsd_makefiles_saproc.make,v 1.1 2017/07/24 12:27:33 wiz Exp $

--- hotspot/make/bsd/makefiles/saproc.make.orig	2017-04-27 09:45:08.000000000 +0000
+++ hotspot/make/bsd/makefiles/saproc.make
@@ -107,7 +107,6 @@ ifneq ($(filter-out ia64 arm zero,$(SRCA
 endif
 endif
 
-
 ifneq ($(OS_VENDOR), Darwin)
 SA_LFLAGS = $(MAPFLAG:FILENAME=$(SAMAPFILE))
 else
@@ -116,6 +115,8 @@ SA_LFLAGS = $(LFLAGS)
 endif
 SA_LFLAGS += $(LDFLAGS_HASH_STYLE)
 
+SA_LFLAGS += $(EXTRA_LDFLAGS)
+
 BOOT_JAVA_INCLUDES = -I$(BOOT_JAVA_HOME)/include \
   -I$(BOOT_JAVA_HOME)/include/$(shell uname -s | tr "[:upper:]" "[:lower:]")
 
