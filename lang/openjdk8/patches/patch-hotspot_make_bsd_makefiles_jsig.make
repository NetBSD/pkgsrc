$NetBSD: patch-hotspot_make_bsd_makefiles_jsig.make,v 1.2 2018/09/15 02:51:02 ryoon Exp $

--- hotspot/make/bsd/makefiles/jsig.make.orig	2018-09-14 14:55:42.000000000 +0000
+++ hotspot/make/bsd/makefiles/jsig.make
@@ -52,7 +52,7 @@ LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfi
 # cause problems with interposing. See CR: 6466665
 # LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
-LFLAGS_JSIG += -D_GNU_SOURCE -pthread $(LDFLAGS_HASH_STYLE) $(LDFLAGS_NO_EXEC_STACK)
+LFLAGS_JSIG += -D_GNU_SOURCE -pthread $(LDFLAGS_HASH_STYLE) $(LDFLAGS_NO_EXEC_STACK) $(EXTRA_LDFLAGS)
 
 # DEBUG_BINARIES overrides everything, use full -g debug information
 ifeq ($(DEBUG_BINARIES), true)
