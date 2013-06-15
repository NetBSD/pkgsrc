$NetBSD: patch-hotspot_make_solaris_makefiles_product.make,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/make/solaris/makefiles/product.make.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/make/solaris/makefiles/product.make
@@ -65,11 +65,16 @@ CFLAGS$(HOTSPARC_GENERIC) += $(OPT_CFLAG
 # Linker mapfiles
 MAPFILE = $(GAMMADIR)/make/solaris/makefiles/mapfile-vers
 
-ifndef USE_GCC
 # This mapfile is only needed when compiling with dtrace support, 
 # and mustn't be otherwise.
-MAPFILE_DTRACE = $(GAMMADIR)/make/solaris/makefiles/mapfile-vers-$(TYPE)
+ifdef USE_GCC
+  MAPFILE_DTRACE = $(GAMMADIR)/make/solaris/makefiles/mapfile-vers-$(TYPE).gcc
+else
+  MAPFILE_DTRACE = $(GAMMADIR)/make/solaris/makefiles/mapfile-vers-$(TYPE)
+endif # USE_GCC
 
+# reorder is not used with gcc
+ifndef USE_GCC
 REORDERFILE = $(GAMMADIR)/make/solaris/makefiles/reorder_$(TYPE)_$(BUILDARCH)
 endif
 
