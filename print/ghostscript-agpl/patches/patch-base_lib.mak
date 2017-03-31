$NetBSD: patch-base_lib.mak,v 1.1 2017/03/31 07:26:23 adam Exp $

Don't depend on zlib objects; instead, link against system zlib.

--- base/lib.mak.orig	2017-03-31 06:55:50.000000000 +0000
+++ base/lib.mak
@@ -3352,9 +3352,7 @@ $(GLOBJ)pdlromfs1.$(OBJ) : $(GLOBJ)pdlro
 
 # Define the ZLIB modules needed by mnkromfs here to factor it out of top makefiles
 # Also put the .h dependencies here for the same reason
-MKROMFS_ZLIB_OBJS=$(AUX)compress.$(OBJ) $(AUX)deflate.$(OBJ) \
-	$(AUX)zutil.$(OBJ) $(AUX)adler32.$(OBJ) $(AUX)crc32.$(OBJ) \
-	$(AUX)trees.$(OBJ)
+MKROMFS_ZLIB_OBJS=
 
 MKROMFS_COMMON_DEPS=$(stdpre_h) $(stdint__h) $(gsiorom_h) $(arch_h)\
 	$(gsmemret_h) $(gsmalloc_h) $(gsstype_h) $(gp_h) $(time__h)
