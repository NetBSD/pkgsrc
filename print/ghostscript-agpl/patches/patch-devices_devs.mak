$NetBSD: patch-devices_devs.mak,v 1.1 2014/04/04 08:48:43 adam Exp $

Don't explicitly depend on zlib.h header file.

--- devices/devs.mak.orig	2014-04-03 16:42:54.000000000 +0000
+++ devices/devs.mak
@@ -1597,7 +1597,7 @@ $(DD)pngalpha.dev : $(DEVS_MAK) $(libpng
 fpng_=$(DEVOBJ)gdevfpng.$(OBJ) $(DEVOBJ)gdevpccm.$(OBJ)
 
 $(DEVOBJ)gdevfpng.$(OBJ) : $(DEVSRC)gdevfpng.c\
- $(gdevprn_h) $(gdevpccm_h) $(gscdefs_h) $(zlib_h)
+ $(gdevprn_h) $(gdevpccm_h) $(gscdefs_h)
 	$(CC_) $(I_)$(DEVI_) $(II)$(PI_)$(_I) $(PCF_) $(GLF_) $(DEVO_)gdevfpng.$(OBJ) $(C_) $(DEVSRC)gdevfpng.c
 
 $(DD)fpng.dev : $(DEVS_MAK) $(fpng_) $(GLD)page.dev $(GDEV)
