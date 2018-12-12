$NetBSD: patch-hotspot_make_bsd_makefiles_saproc.make,v 1.2 2018/12/12 14:22:11 ryoon Exp $

--- hotspot/make/bsd/makefiles/saproc.make.orig	2018-12-09 09:51:15.000000000 +0000
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
 SA_LFLAGS += $(LDFLAGS_HASH_STYLE) $(EXTRA_LDFLAGS)
 
+SA_LFLAGS += $(EXTRA_LDFLAGS)
+
 BOOT_JAVA_INCLUDES = -I$(BOOT_JAVA_HOME)/include \
   -I$(BOOT_JAVA_HOME)/include/$(shell uname -s | tr "[:upper:]" "[:lower:]")
 
