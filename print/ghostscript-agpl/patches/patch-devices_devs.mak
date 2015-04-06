$NetBSD: patch-devices_devs.mak,v 1.3 2015/04/06 11:24:55 adam Exp $

Don't depend on src/zlib.h.

--- devices/devs.mak.orig	2015-04-06 11:15:42.000000000 +0000
+++ devices/devs.mak
@@ -1231,7 +1231,7 @@ $(libtiff_dev) $(MAKEDIRS)
 
 $(DEVOBJ)gdevxps.$(OBJ) : $(DEVVECSRC)gdevxps.c $(gdevvec_h) \
 $(string__h) $(stdio__h) $(libtiff_dev) $(gx_h) $(gserrors_h) \
-$(gxpath_h) $(gzcpath_h) $(stream_h) $(zlib_h) \
+$(gxpath_h) $(gzcpath_h) $(stream_h) \
 $(stdint__h) $(gdevtifs_h) $(gsicc_create_h) $(gsicc_cache_h) \
 $(gximdecode_h) $(MAKEDIRS)
 	$(XPSDEVCC) $(I_)$(TI_)$(_I) $(GLO_)gdevxps.$(OBJ) $(C_) $(DEVVECSRC)gdevxps.c
