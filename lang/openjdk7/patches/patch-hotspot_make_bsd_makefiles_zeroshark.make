$NetBSD: patch-hotspot_make_bsd_makefiles_zeroshark.make,v 1.1 2015/02/08 23:40:09 tnn Exp $

--- hotspot/make/bsd/makefiles/zeroshark.make.orig	2015-01-26 15:21:52.000000000 +0000
+++ hotspot/make/bsd/makefiles/zeroshark.make
@@ -57,6 +57,6 @@ else
 endif
 
 CFLAGS += -I$(PACKAGE_PATH)/include
-LIBS += -L$(PACKAGE_PATH)/lib -lffi
+LIBS += -Wl,-R$(PACKAGE_PATH)/lib -L$(PACKAGE_PATH)/lib -lffi
 
 OPT_CFLAGS/compactingPermGenGen.o = -O1
