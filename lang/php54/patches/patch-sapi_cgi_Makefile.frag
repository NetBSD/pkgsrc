$NetBSD: patch-sapi_cgi_Makefile.frag,v 1.1 2012/06/16 05:21:55 taca Exp $

--- sapi/cgi/Makefile.frag.orig	2012-05-03 17:10:43.000000000 +0000
+++ sapi/cgi/Makefile.frag
@@ -4,6 +4,6 @@ $(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(P
 	$(BUILD_CGI)
 
 install-cgi: $(SAPI_CGI_PATH)
-	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)$(bindir)/"
-	@$(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)$(bindir)/$(program_prefix)php-cgi$(program_suffix)$(EXEEXT)
+	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)@CGIDIR@/"
+	@$(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)@CGIDIR@/php
 
