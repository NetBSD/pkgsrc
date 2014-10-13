$NetBSD: patch-external_coinmp_ExternalProject__coinmp.mk,v 1.1 2014/10/13 21:52:50 ryoon Exp $

* Use libtool from pkgsrc/devel/libtool

--- external/coinmp/ExternalProject_coinmp.mk.orig	2014-09-16 20:10:41.000000000 +0000
+++ external/coinmp/ExternalProject_coinmp.mk
@@ -26,6 +26,7 @@ $(call gb_ExternalProject_get_state_targ
 else
 $(call gb_ExternalProject_get_state_target,coinmp,build) :
 	+$(call gb_ExternalProject_run,build,\
+		ln -s ${PREFIX}/bin/libtool libtool && \
 		./configure COIN_SKIP_PROJECTS="Data/Sample" \
 			$(if $(CROSS_COMPILING),--build=$(BUILD_PLATFORM) --host=$(HOST_PLATFORM)) \
 			$(if $(DISABLE_DYNLOADING),--disable-shared) \
