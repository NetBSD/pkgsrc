$NetBSD: patch-solenv_gbuild_AllLangResTarget.mk,v 1.2 2016/02/11 09:45:27 ryoon Exp $

--- solenv/gbuild/AllLangResTarget.mk.orig	2016-01-27 00:58:25.000000000 +0000
+++ solenv/gbuild/AllLangResTarget.mk
@@ -88,7 +88,6 @@ $(call gb_Helper_abbreviate_dirs,\
 	echo "-s \
 		$(INCLUDE) \
 		-I$(dir $(3)) \
-		$(DEFS) \
 		-fp=$(1) \
 		$(if $(MERGEDFILE),$(MERGEDFILE),$<)" > $${RESPONSEFILE} && \
 	$(gb_ResTarget_RSCCOMMAND) -presponse @$${RESPONSEFILE} && \
