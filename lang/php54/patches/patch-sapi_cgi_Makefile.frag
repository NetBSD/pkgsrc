$NetBSD: patch-sapi_cgi_Makefile.frag,v 1.3 2013/09/21 16:06:07 taca Exp $

Install cgi binary as php instead of php-cgi.

--- sapi/cgi/Makefile.frag.orig	2013-09-18 05:48:57.000000000 +0000
+++ sapi/cgi/Makefile.frag
@@ -6,7 +6,8 @@ $(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(P
 install-cgi: $(SAPI_CGI_PATH)
 	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)$(bindir)/"
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
-	@$(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)$(bindir)/$(program_prefix)php-cgi$(program_suffix)$(EXEEXT)
+	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)@CGIDIR@/"
+	@$(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)@CGIDIR@/$(program_prefix)php$(program_suffix)$(EXEEXT)
 	@echo "Installing PHP CGI man page:      $(INSTALL_ROOT)$(mandir)/man1/"
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man1
 	@$(INSTALL_DATA) sapi/cgi/php-cgi.1 $(INSTALL_ROOT)$(mandir)/man1/$(program_prefix)php-cgi$(program_suffix).1
