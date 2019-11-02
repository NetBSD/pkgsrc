$NetBSD: patch-hotspot_make_solaris_makefiles_jsig.make,v 1.3 2019/11/02 21:31:14 tnn Exp $

GCC support.

--- hotspot/make/solaris/makefiles/jsig.make.orig	2019-10-16 01:41:55.000000000 +0000
+++ hotspot/make/solaris/makefiles/jsig.make
@@ -39,10 +39,11 @@ DEST_JSIG_DIZ       = $(JDK_LIBDIR)/$(LI
 
 LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfile-vers-jsig
 
+LFLAGS_JSIG += $(CFLAGS)
 LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
 ifdef USE_GCC
-LFLAGS_JSIG += -D_REENTRANT
+LFLAGS_JSIG += -D_GNU_SOURCE -D_REENTRANT
 else
 LFLAGS_JSIG += -mt -xnolib
 endif
@@ -52,6 +53,13 @@ ifneq ($(DEBUG_LEVEL), slowdebug)
   JSIG_OPT_FLAGS = -xO4 -g
 endif
 
+# DEBUG_BINARIES overrides everything, use full -g debug information
+ifdef USE_GCC
+  ifeq ($(DEBUG_BINARIES), true)
+    JSIG_OPT_FLAGS = -g
+  endif
+endif
+
 $(LIBJSIG): $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
 	@echo Making signal interposition lib...
 	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) $(SHARED_FLAG) $(PICFLAG) \
