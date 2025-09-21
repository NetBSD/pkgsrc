$NetBSD: patch-base_lib.mak,v 1.2 2025/09/21 18:19:54 wiz Exp $

Don't depend on zlib objects; instead, link against system zlib.

--- base/lib.mak.orig	2025-09-09 09:36:39.000000000 +0000
+++ base/lib.mak
@@ -3683,9 +3683,7 @@ $(GLOBJ)pdlromfs1c3.$(OBJ) : $(GLOBJ)pdl
 
 # Define the ZLIB modules needed by mkromfs here to factor it out of top makefiles
 # Also put the .h dependencies here for the same reason
-MKROMFS_ZLIB_OBJS=$(AUX)compress.$(OBJ) $(AUX)deflate.$(OBJ) \
-	$(AUX)zutil.$(OBJ) $(AUX)adler32.$(OBJ) $(AUX)crc32.$(OBJ) \
-	$(AUX)trees.$(OBJ)
+MKROMFS_ZLIB_OBJS=
 
 MKROMFS_BROTLI_OBJS=\
 	$(AUX)constants.$(OBJ) \
