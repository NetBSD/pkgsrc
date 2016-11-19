$NetBSD: patch-libinterp_dldfcn_module.mk,v 1.2 2016/11/19 21:53:12 maya Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/module.mk.orig	2016-11-13 15:22:17.000000000 +0000
+++ libinterp/dldfcn/module.mk
@@ -39,7 +39,7 @@ octlib_LTLIBRARIES += $(DLDFCN_LIBS)
 ## of symbolic links
 
 %.oct : %.la
-	$(AM_V_GEN)$(INSTALL_PROGRAM) libinterp/dldfcn/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
+	$(AM_V_GEN)$(INSTALL_LIB) libinterp/dldfcn/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
 
 else
 
