$NetBSD: patch-devices_devs.mak,v 1.5 2016/04/07 08:52:06 adam Exp $

Don't depend on src/zlib.h.

--- devices/devs.mak.orig	2016-03-23 08:22:48.000000000 +0000
+++ devices/devs.mak
@@ -1233,7 +1233,7 @@ $(gximdecode_h) $(DEVS_MAK) $(MAKEDIRS)
 
 $(DEVOBJ)gdevxps_0.$(OBJ) : $(DEVVECSRC)gdevxps.c $(gdevvec_h) \
 $(string__h) $(stdio__h) $(libtiff_dev) $(gx_h) $(gserrors_h) \
-$(gxpath_h) $(gzcpath_h) $(stream_h) $(zlib_h) \
+$(gxpath_h) $(gzcpath_h) $(stream_h) \
 $(stdint__h) $(gdevtifs_h) $(gsicc_create_h) $(gsicc_cache_h) \
 $(gximdecode_h) $(DEVS_MAK) $(MAKEDIRS)
 	$(XPSDEVCC) $(I_)$(TI_)$(_I) $(GLO_)gdevxps_0.$(OBJ) $(C_) $(DEVVECSRC)gdevxps.c
@@ -1417,7 +1417,7 @@ $(DEVOBJ)gdevgprf_1.$(OBJ) : $(DEVSRC)gd
 
 $(DEVOBJ)gdevgprf_0.$(OBJ) : $(DEVSRC)gdevgprf.c $(PDEVH) $(math__h)\
  $(gdevdcrd_h) $(gscrd_h) $(gscrdp_h) $(gsparam_h) $(gxlum_h)\
- $(gstypes_h) $(gxdcconv_h) $(gdevdevn_h) $(gsequivc_h) $(zlib_h)\
+ $(gstypes_h) $(gxdcconv_h) $(gdevdevn_h) $(gsequivc_h) \
  $(gscms_h) $(gsicc_cache_h) $(gsicc_manage_h) $(gxgetbit_h)\
  $(gdevppla_h) $(DEVS_MAK) $(MAKEDIRS)
 	$(DEVCC) $(DEVO_)gdevgprf_0.$(OBJ) $(II)$(ZI_)$(_I) $(C_) $(DEVSRC)gdevgprf.c
