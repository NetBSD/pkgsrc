$NetBSD: patch-hotspot_make_solaris_makefiles_jsig.make,v 1.4 2019/11/05 22:30:15 jperkin Exp $

GCC support.

--- hotspot/make/solaris/makefiles/jsig.make.orig	2019-10-16 01:41:55.000000000 +0000
+++ hotspot/make/solaris/makefiles/jsig.make
@@ -39,17 +39,27 @@ DEST_JSIG_DIZ       = $(JDK_LIBDIR)/$(LI
 
 LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfile-vers-jsig
 
+LFLAGS_JSIG += $(CFLAGS)
 LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
 ifdef USE_GCC
-LFLAGS_JSIG += -D_REENTRANT
+LFLAGS_JSIG += -D_GNU_SOURCE -D_REENTRANT
 else
 LFLAGS_JSIG += -mt -xnolib
 endif
 
 # Optimize jsig lib unless it's a slowdebug build
 ifneq ($(DEBUG_LEVEL), slowdebug)
+ ifndef USE_GCC
   JSIG_OPT_FLAGS = -xO4 -g
+ endif
+endif
+
+# DEBUG_BINARIES overrides everything, use full -g debug information
+ifdef USE_GCC
+  ifeq ($(DEBUG_BINARIES), true)
+    JSIG_OPT_FLAGS = -g
+  endif
 endif
 
 $(LIBJSIG): $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
