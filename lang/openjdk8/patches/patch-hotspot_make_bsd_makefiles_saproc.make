$NetBSD: patch-hotspot_make_bsd_makefiles_saproc.make,v 1.3 2026/08/14 12:48:02 ryoon Exp $

--- hotspot/make/bsd/makefiles/saproc.make.orig	2026-07-23 23:26:52.000000000 +0000
+++ hotspot/make/bsd/makefiles/saproc.make
@@ -114,7 +114,6 @@ endif
 endif
 endif
 
-
 ifneq ($(OS_VENDOR), Darwin)
   SA_LFLAGS = $(MAPFLAG:FILENAME=$(SAMAPFILE))
 else
@@ -122,6 +121,8 @@ SA_LFLAGS += $(LDFLAGS_HASH_STYLE) $(EXTRA_LDFLAGS)
   SA_LFLAGS = $(MAC_FLAGS)
 endif
 SA_LFLAGS += $(LDFLAGS_HASH_STYLE) $(EXTRA_LDFLAGS)
+
+SA_LFLAGS += $(EXTRA_LDFLAGS)
 
 BOOT_JAVA_INCLUDES = -I$(BOOT_JAVA_HOME)/include \
   -I$(BOOT_JAVA_HOME)/include/$(shell uname -s | tr "[:upper:]" "[:lower:]")
