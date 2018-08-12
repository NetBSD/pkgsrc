$NetBSD: patch-libinterp_dldfcn_module.mk,v 1.3 2018/08/12 08:33:55 maya Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/module.mk.orig	2018-08-09 18:20:32.000000000 +0000
+++ libinterp/dldfcn/module.mk
@@ -40,7 +40,7 @@ octlib_LTLIBRARIES += $(DLDFCN_LIBS)
 ## of symbolic links
 
 %.oct : %.la
-	$(AM_V_GEN)$(INSTALL_PROGRAM) %reldir%/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
+	$(AM_V_GEN)$(INSTALL_LIB) %reldir%/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
 
 else
 
