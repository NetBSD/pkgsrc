$NetBSD: patch-solenv_gbuild_AllLangResTarget.mk,v 1.1 2013/10/04 14:44:46 ryoon Exp $

* Fix build. rsc command does not acceprt "-pthread", it is not needed.

--- solenv/gbuild/AllLangResTarget.mk.orig	2013-08-21 11:40:03.000000000 +0000
+++ solenv/gbuild/AllLangResTarget.mk
@@ -86,7 +86,6 @@ $(call gb_Helper_abbreviate_dirs,\
 	echo "-s \
 		$(INCLUDE) \
 		-I$(dir $(3)) \
-		$(DEFS) \
 		-fp=$(1) \
 		$(if $(MERGEDFILE),$(MERGEDFILE),$<)" > $${RESPONSEFILE} && \
 	$(gb_ResTarget_RSCCOMMAND) -presponse @$${RESPONSEFILE} && \
