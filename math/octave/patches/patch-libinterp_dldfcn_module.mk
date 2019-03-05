$NetBSD: patch-libinterp_dldfcn_module.mk,v 1.4 2019/03/05 11:11:12 ryoon Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/module.mk.orig	2019-02-23 17:33:37.000000000 +0000
+++ libinterp/dldfcn/module.mk
@@ -37,7 +37,7 @@ octlib_LTLIBRARIES += $(DLDFCN_LIBS)
 ## of symbolic links
 
 %.oct : %.la
-	$(AM_V_GEN)$(INSTALL_PROGRAM) %reldir%/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
+	$(AM_V_GEN)$(INSTALL_LIB) %reldir%/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
 
 %canon_reldir%___delaunayn___la_SOURCES = %reldir%/__delaunayn__.cc
 %canon_reldir%___delaunayn___la_CPPFLAGS = $(libinterp_liboctinterp_la_CPPFLAGS) $(QHULL_CPPFLAGS)
