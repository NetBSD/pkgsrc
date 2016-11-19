$NetBSD: patch-libinterp_module.mk,v 1.1 2016/11/19 21:53:12 maya Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/module.mk.orig	2016-11-13 15:16:10.000000000 +0000
+++ libinterp/module.mk
@@ -306,7 +306,7 @@ install-oct:
 	  f=`echo $$ltlib | $(SED) 's,.*/,,'`; \
 	  dl=`$(SED) -n -e "s/dlname='\([^']*\)'/\1/p" < $$f`; \
 	  if [ -n "$$dl" ]; then \
-	    $(INSTALL_PROGRAM) $$dl $(DESTDIR)$(octfiledir)/`echo $$f | $(SED) 's,^lib,,; s,\.la$$,.oct,'`; \
+	    $(INSTALL_LIB) $$dl $(DESTDIR)$(octfiledir)/`echo $$f | $(SED) 's,^lib,,; s,\.la$$,.oct,'`; \
 	  else \
 	    echo "error: dlname is empty in $$ltlib!"; \
 	    exit 1; \
