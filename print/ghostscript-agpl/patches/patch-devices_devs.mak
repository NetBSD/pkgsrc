$NetBSD: patch-devices_devs.mak,v 1.7 2020/03/24 16:34:45 adam Exp $

Don't depend on src/zlib.h.

--- devices/devs.mak.orig	2020-03-19 08:21:42.000000000 +0000
+++ devices/devs.mak
@@ -1093,7 +1093,7 @@ $(gximdecode_h) $(DEVS_MAK) $(MAKEDIRS)
 
 $(DEVOBJ)gdevxps_0.$(OBJ) : $(DEVVECSRC)gdevxps.c $(gdevvec_h) \
 $(string__h) $(stdio__h) $(libtiff_dev) $(gx_h) $(gserrors_h) \
-$(gxpath_h) $(gzcpath_h) $(stream_h) $(zlib_h) \
+$(gxpath_h) $(gzcpath_h) $(stream_h) \
 $(stdint__h) $(gdevtifs_h) $(gsicc_create_h) $(gsicc_cache_h) \
 $(gximdecode_h) $(DEVS_MAK) $(MAKEDIRS)
 	$(XPSDEVCC) $(I_)$(TI_)$(_I) $(GLO_)gdevxps_0.$(OBJ) $(C_) $(DEVVECSRC)gdevxps.c
@@ -1514,7 +1514,7 @@ $(DD)pngalpha.dev : $(libpng_dev) $(png_
 fpng_=$(DEVOBJ)gdevfpng.$(OBJ) $(DEVOBJ)gdevpccm.$(OBJ)
 
 $(DEVOBJ)gdevfpng_0.$(OBJ) : $(DEVSRC)gdevfpng.c\
- $(gdevprn_h) $(gxdevsop_h) $(gdevpccm_h) $(gscdefs_h) $(zlib_h) $(DEVS_MAK) $(MAKEDIRS)
+ $(gdevprn_h) $(gxdevsop_h) $(gdevpccm_h) $(gscdefs_h) $(DEVS_MAK) $(MAKEDIRS)
 	$(CC_) $(I_)$(DEVI_) $(II)$(ZI_)$(_I) $(PCF_) $(GLF_) $(DEVO_)gdevfpng_0.$(OBJ) $(C_) $(DEVSRC)gdevfpng.c
 
 $(DEVOBJ)gdevfpng_1.$(OBJ) : $(DEVSRC)gdevfpng.c\
