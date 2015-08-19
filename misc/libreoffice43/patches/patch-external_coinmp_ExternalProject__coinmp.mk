$NetBSD: patch-external_coinmp_ExternalProject__coinmp.mk,v 1.1 2015/08/19 07:11:44 he Exp $

* Use libtool from pkgsrc/devel/libtool

--- external/coinmp/ExternalProject_coinmp.mk.orig	2014-11-10 11:52:56.000000000 +0000
+++ external/coinmp/ExternalProject_coinmp.mk
@@ -26,6 +26,7 @@ $(call gb_ExternalProject_get_state_targ
 else
 $(call gb_ExternalProject_get_state_target,coinmp,build) :
 	+$(call gb_ExternalProject_run,build,\
+		ln -s ${PREFIX}/bin/libtool libtool && \
 		./configure COIN_SKIP_PROJECTS="Data/Sample" \
 			$(if $(CROSS_COMPILING),--build=$(BUILD_PLATFORM) --host=$(HOST_PLATFORM)) \
 			$(if $(DISABLE_DYNLOADING),--disable-shared) \
