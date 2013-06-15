$NetBSD: patch-hotspot_make_solaris_makefiles_jsig.make,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/make/solaris/makefiles/jsig.make.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/make/solaris/makefiles/jsig.make
@@ -47,15 +47,25 @@ LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfi
 LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
 ifdef USE_GCC
-LFLAGS_JSIG += -D_REENTRANT
+  LFLAGS_JSIG += -D_GNU_SOURCE -D_REENTRANT
 else
-LFLAGS_JSIG += -mt -xnolib
+  LFLAGS_JSIG += -mt -xnolib
+endif
+
+# DEBUG_BINARIES overrides everything, use full -g debug information
+ifeq ($(DEBUG_BINARIES), true)
+  JSIG_DEBUG_CFLAGS = -g
 endif
 
 $(LIBJSIG): $(ADD_GNU_DEBUGLINK) $(FIX_EMPTY_SEC_HDR_FLAGS) $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
 	@echo Making signal interposition lib...
+ifdef USE_GCC
+	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) $(SHARED_FLAG) $(PICFLAG) \
+                         $(LFLAGS_JSIG) $(JSIG_DEBUG_CFLAGS) -o $@ $(JSIGSRCDIR)/jsig.c -ldl
+else
 	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) $(SHARED_FLAG) $(PICFLAG) \
                          $(LFLAGS_JSIG) -o $@ $(JSIGSRCDIR)/jsig.c -ldl
+endif
 	[ -f $(LIBJSIG_G) ] || { ln -s $@ $(LIBJSIG_G); }
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 # gobjcopy crashes on "empty" section headers with the SHF_ALLOC flag set.
