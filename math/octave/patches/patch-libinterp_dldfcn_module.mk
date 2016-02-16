$NetBSD: patch-libinterp_dldfcn_module.mk,v 1.1 2016/02/16 04:21:40 dbj Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/module.mk.orig	2015-05-23 14:36:42.000000000 +0000
+++ libinterp/dldfcn/module.mk
@@ -39,7 +39,7 @@ octlib_LTLIBRARIES += $(DLDFCN_LIBS)
 ## of symbolic links
 
 %.oct : %.la
-	$(AM_V_GEN)$(INSTALL_PROGRAM) dldfcn/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
+	$(AM_V_GEN)$(INSTALL_LIB) dldfcn/.libs/$(shell $(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $<) $@
 
 else
 
