$NetBSD: patch-hotspot_make_solaris_makefiles_saproc.make,v 1.1 2013/06/15 09:31:05 jperkin Exp $

Only use libdemangle for Sun Studio builds.

--- hotspot/make/solaris/makefiles/saproc.make.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/make/solaris/makefiles/saproc.make
@@ -61,6 +61,7 @@ ifdef USE_GCC
 SA_LFLAGS += -D_REENTRANT
 else
 SA_LFLAGS += -mt -xnolib -norunpath
+LIBDEMANGLE = -ldemangle
 endif
 
 # The libproc Pstack_iter() interface changed in Nevada-B159.
@@ -106,7 +107,7 @@ $(LIBSAPROC): $(ADD_GNU_DEBUGLINK) $(FIX
 	           $(SASRCFILES)                                        \
 	           $(SA_LFLAGS)                                         \
 	           -o $@                                                \
-	           -ldl -ldemangle -lthread -lc
+	           -ldl ${LIBDEMANGLE} -lthread -lc
 	[ -f $(LIBSAPROC_G) ] || { ln -s $@ $(LIBSAPROC_G); }
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 # gobjcopy crashes on "empty" section headers with the SHF_ALLOC flag set.
