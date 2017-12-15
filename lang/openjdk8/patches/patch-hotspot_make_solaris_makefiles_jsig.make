$NetBSD: patch-hotspot_make_solaris_makefiles_jsig.make,v 1.2 2017/12/15 14:27:52 jperkin Exp $

GCC support.

--- hotspot/make/solaris/makefiles/jsig.make.orig	2017-11-28 00:13:38.000000000 +0000
+++ hotspot/make/solaris/makefiles/jsig.make
@@ -39,18 +39,29 @@ DEST_JSIG_DIZ       = $(JDK_LIBDIR)/$(LI
 
 LIBJSIG_MAPFILE = $(MAKEFILES_DIR)/mapfile-vers-jsig
 
+LFLAGS_JSIG += $(CFLAGS)
 LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
 ifdef USE_GCC
-LFLAGS_JSIG += -D_REENTRANT
+LFLAGS_JSIG += -D_GNU_SOURCE -D_REENTRANT
 else
 LFLAGS_JSIG += -mt -xnolib
 endif
 
+# DEBUG_BINARIES overrides everything, use full -g debug information
+ifeq ($(DEBUG_BINARIES), true)
+JSIG_DEBUG_CFLAGS = -g
+endif
+
 $(LIBJSIG): $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
 	@echo Making signal interposition lib...
+ifdef USE_GCC
+	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) $(SHARED_FLAG) $(PICFLAG) \
+                         $(LFLAGS_JSIG) $(JSIG_DEBUG_CFLAGS) -o $@ $(JSIGSRCDIR)/jsig.c -ldl
+else
 	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) $(SHARED_FLAG) $(PICFLAG) \
                          $(LFLAGS_JSIG) -o $@ $(JSIGSRCDIR)/jsig.c -ldl
+endif
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 	$(QUIETLY) $(OBJCOPY) --only-keep-debug $@ $(LIBJSIG_DEBUGINFO)
 	$(QUIETLY) $(OBJCOPY) --add-gnu-debuglink=$(LIBJSIG_DEBUGINFO) $@
