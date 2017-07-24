$NetBSD: patch-hotspot_make_bsd_makefiles_jsig.make,v 1.1 2017/07/24 12:27:33 wiz Exp $

--- hotspot/make/bsd/makefiles/jsig.make.orig	2017-04-27 09:45:08.000000000 +0000
+++ hotspot/make/bsd/makefiles/jsig.make
@@ -52,7 +52,7 @@ LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfi
 # cause problems with interposing. See CR: 6466665
 # LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
-LFLAGS_JSIG += -D_GNU_SOURCE -pthread $(LDFLAGS_HASH_STYLE)
+LFLAGS_JSIG += -D_GNU_SOURCE -pthread $(LDFLAGS_HASH_STYLE) $(EXTRA_LDFLAGS)
 
 # DEBUG_BINARIES overrides everything, use full -g debug information
 ifeq ($(DEBUG_BINARIES), true)
