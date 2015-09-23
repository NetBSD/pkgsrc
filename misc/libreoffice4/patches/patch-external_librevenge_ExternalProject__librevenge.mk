$NetBSD: patch-external_librevenge_ExternalProject__librevenge.mk,v 1.1 2015/09/23 20:45:50 joerg Exp $

Pick up and apply some diffs based on

http://pkgs.fedoraproject.org/cgit/libreoffice.git/commit/?id=57cfb98d1c45259f946ff3444eeb6891a030e063

which makes libreoffice43 build with boost 1.59.

--- external/librevenge/ExternalProject_librevenge.mk.orig	2015-04-20 19:36:29.000000000 +0000
+++ external/librevenge/ExternalProject_librevenge.mk
@@ -35,7 +35,10 @@ $(call gb_ExternalProject_get_state_targ
 			--disable-generators \
 			--without-docs \
 			$(if $(VERBOSE)$(verbose),--disable-silent-rules,--enable-silent-rules) \
-			CXXFLAGS="$(if $(SYSTEM_BOOST),$(BOOST_CPPFLAGS),-I$(call gb_UnpackedTarball_get_dir,boost))" \
+			CXXFLAGS="$(if $(SYSTEM_BOOST),$(BOOST_CPPFLAGS),-I$(call gb_UnpackedTarball_get_dir,boost) \
+			-DBOOST_ERROR_CODE_HEADER_ONLY \
+			-DBOOST_SYSTEM_NO_DEPRECATED \
+			-I$(BUILDDIR)/config_$(gb_Side))" \
 			$(if $(CROSS_COMPILING),--build=$(BUILD_PLATFORM) --host=$(HOST_PLATFORM)) \
 			$(if $(filter MACOSX,$(OS)),--prefix=/@.__________________________________________________OOO) \
 		&& $(MAKE) \
