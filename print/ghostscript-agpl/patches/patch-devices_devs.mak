$NetBSD: patch-devices_devs.mak,v 1.4 2015/10/10 11:55:19 adam Exp $

Don't depend on src/zlib.h.

--- devices/devs.mak.orig	2015-10-05 08:21:11.000000000 +0000
+++ devices/devs.mak
@@ -1226,7 +1226,7 @@ $(libtiff_dev) $(MAKEDIRS)
 
 $(DEVOBJ)gdevxps.$(OBJ) : $(DEVVECSRC)gdevxps.c $(gdevvec_h) \
 $(string__h) $(stdio__h) $(libtiff_dev) $(gx_h) $(gserrors_h) \
-$(gxpath_h) $(gzcpath_h) $(stream_h) $(zlib_h) \
+$(gxpath_h) $(gzcpath_h) $(stream_h) \
 $(stdint__h) $(gdevtifs_h) $(gsicc_create_h) $(gsicc_cache_h) \
 $(gximdecode_h) $(MAKEDIRS)
 	$(XPSDEVCC) $(I_)$(TI_)$(_I) $(GLO_)gdevxps.$(OBJ) $(C_) $(DEVVECSRC)gdevxps.c
@@ -1399,7 +1399,7 @@ $(DD)gprf.dev : $(DEVS_MAK) $(gprf_) $(G
 
 $(DEVOBJ)gdevgprf.$(OBJ) : $(DEVSRC)gdevgprf.c $(PDEVH) $(math__h)\
  $(gdevdcrd_h) $(gscrd_h) $(gscrdp_h) $(gsparam_h) $(gxlum_h)\
- $(gstypes_h) $(gxdcconv_h) $(gdevdevn_h) $(gsequivc_h) $(zlib_h)\
+ $(gstypes_h) $(gxdcconv_h) $(gdevdevn_h) $(gsequivc_h) \
  $(gscms_h) $(gsicc_cache_h) $(gsicc_manage_h) $(gxgetbit_h)\
  $(gdevppla_h) $(MAKEDIRS)
 	$(DEVCC) $(DEVO_)gdevgprf.$(OBJ) $(II)$(ZI_)$(_I) $(C_) $(DEVSRC)gdevgprf.c
