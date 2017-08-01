$NetBSD: patch-solenv_gbuild_AllLangResTarget.mk,v 1.4 2017/08/01 11:57:37 ryoon Exp $

* Do not pass arguments to RSC. Prevent a build failure

--- solenv/gbuild/AllLangResTarget.mk.orig	2017-07-25 20:26:39.000000000 +0000
+++ solenv/gbuild/AllLangResTarget.mk
@@ -85,7 +85,6 @@ $(call gb_Helper_abbreviate_dirs,\
 	echo "-s \
 		$(INCLUDE) \
 		-I$(dir $(3)) \
-		$(DEFS) \
 		-D__RSC \
 		-fp=$(1) \
 		$(if $(MERGEDFILE),$(MERGEDFILE),$<)" > $${RESPONSEFILE} && \
