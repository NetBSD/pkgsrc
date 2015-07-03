$NetBSD: patch-hotspot_make_solaris_makefiles_vm.make,v 1.1 2015/07/03 20:40:59 fhajny Exp $

GCC support.

--- hotspot/make/solaris/makefiles/vm.make.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/make/solaris/makefiles/vm.make
@@ -59,7 +59,11 @@ INCLUDES += $(Src_Dirs_I:%=-I%)
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
   # always build with debug info when we can create .debuginfo files
   # and disable 'lazy debug info' so the .so has everything.
-  SYMFLAG = -g -xs
+  ifdef USE_GCC
+    SYMFLAG = -g
+  else
+    SYMFLAG = -g -xs
+  endif
 else
   ifeq (${VERSION}, debug)
     SYMFLAG = -g
@@ -271,16 +275,19 @@ ifeq ($(LINK_INTO),AOUT)
   LIBS_VM                  = $(LIBS)
 else
   LIBJVM.o                 = $(JVM_OBJ_FILES)
-  LIBJVM_MAPFILE$(LDNOMAP) = mapfile_extended
-  LFLAGS_VM$(LDNOMAP)      += $(MAPFLAG:FILENAME=$(LIBJVM_MAPFILE))
   LFLAGS_VM                += $(SONAMEFLAG:SONAME=$(LIBJVM))
 ifndef USE_GCC
   LIBS_VM                  = $(LIBS)
+  LIBJVM_MAPFILE$(LDNOMAP) = mapfile_extended
+  LFLAGS_VM$(LDNOMAP)      += $(MAPFLAG:FILENAME=$(LIBJVM_MAPFILE))
 else
   # JVM is statically linked with libgcc[_s] and libstdc++; this is needed to
   # get around library dependency and compatibility issues. Must use gcc not
   # g++ to link.
   LFLAGS_VM                += $(STATIC_LIBGCC)
+  ifeq ($(BUILDARCH),i486)
+    LFLAGS_VM              += -mimpure-text
+  endif
   LIBS_VM                  += $(STATIC_STDCXX) $(LIBS)
 endif
 endif
