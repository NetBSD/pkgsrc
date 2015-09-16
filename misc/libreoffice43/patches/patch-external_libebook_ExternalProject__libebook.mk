$NetBSD: patch-external_libebook_ExternalProject__libebook.mk,v 1.1 2015/09/16 21:12:39 he Exp $

Pick up and apply some diffs based on

http://pkgs.fedoraproject.org/cgit/libreoffice.git/commit/?id=57cfb98d1c45259f946ff3444eeb6891a030e063

which makes libreoffice43 build with boost 1.59.

--- external/libebook/ExternalProject_libebook.mk.orig	2015-04-20 19:36:29.000000000 +0000
+++ external/libebook/ExternalProject_libebook.mk
@@ -38,7 +38,10 @@ $(call gb_ExternalProject_get_state_targ
 			$(if $(VERBOSE)$(verbose),--disable-silent-rules,--enable-silent-rules) \
 			--disable-werror \
 			--disable-weffc \
-			CXXFLAGS="$(if $(SYSTEM_BOOST),$(BOOST_CPPFLAGS),-I$(call gb_UnpackedTarball_get_dir,boost) -I$(BUILDDIR)/config_$(gb_Side))" \
+			CXXFLAGS="$(if $(SYSTEM_BOOST),$(BOOST_CPPFLAGS),-I$(call gb_UnpackedTarball_get_dir,boost) \
+			-DBOOST_ERROR_CODE_HEADER_ONLY \
+			-DBOOST_SYSTEM_NO_DEPRECATED \
+			-I$(BUILDDIR)/config_$(gb_Side))" \
 			XML_CFLAGS="$(LIBXML_CFLAGS)" \
 			XML_LIBS="$(LIBXML_LIBS)" \
 			REVENGE_GENERATORS_CFLAGS=' ' REVENGE_GENERATORS_LIBS=' ' REVENGE_STREAM_CFLAGS=' ' REVENGE_STREAM_LIBS=' ' \
