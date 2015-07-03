$NetBSD: patch-hotspot_make_solaris_makefiles_saproc.make,v 1.1 2015/07/03 20:40:59 fhajny Exp $

Only use libdemangle for Sun Studio builds.

--- hotspot/make/solaris/makefiles/saproc.make.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/make/solaris/makefiles/saproc.make
@@ -60,6 +60,7 @@ ifdef USE_GCC
 SA_LFLAGS += -D_REENTRANT
 else
 SA_LFLAGS += -mt -xnolib -norunpath
+LIBDEMANGLE = -ldemangle
 endif
 
 # The libproc Pstack_iter() interface changed in Nevada-B159.
@@ -107,7 +108,7 @@ $(LIBSAPROC): $(ADD_GNU_DEBUGLINK) $(FIX
 	           $(SADISOBJ)                                          \
 	           $(SA_LFLAGS)                                         \
 	           -o $@                                                \
-	           -ldl -ldemangle -lthread -lc
+	           -ldl ${LIBDEMANGLE} -lthread -lc
 
 $(SADISOBJ): $(SADISSRCFILES)
 	           $(QUIETLY) $(CC)                                     \
