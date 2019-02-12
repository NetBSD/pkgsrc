$NetBSD: patch-examples.mk,v 1.1 2019/02/12 20:47:14 adam Exp $

--- examples.mk.orig	2015-11-09 22:12:38.000000000 +0000
+++ examples.mk
@@ -294,7 +294,7 @@ else
 SHARED_LIB_SUF=.so
 endif
 endif
-CODEC_LIB_SUF=$(if $(CONFIG_SHARED),$(SHARED_LIB_SUF),.a)
+CODEC_LIB_SUF=$(if $(CONFIG_SHARED),$(SHARED_LIB_SUF),.la)
 $(foreach bin,$(BINS-yes),\
     $(eval $(bin):$(LIB_PATH)/lib$(CODEC_LIB)$(CODEC_LIB_SUF))\
     $(eval $(call linker_template,$(bin),\
