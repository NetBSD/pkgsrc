$NetBSD: patch-sapi_cgi_Makefile.frag,v 1.2 2026/03/15 15:29:11 taca Exp $

Install to CGI directory.

--- sapi/cgi/Makefile.frag.orig	2026-03-10 15:51:04.000000000 +0000
+++ sapi/cgi/Makefile.frag
@@ -4,9 +4,9 @@ $(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(P
 	$(BUILD_CGI)
 
 install-cgi: $(SAPI_CGI_PATH)
-	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)$(bindir)/"
+	@echo "Installing PHP CGI binary:        $(INSTALL_ROOT)@CGIDIR@/"
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
-	@$(LIBTOOL) --mode=install $(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)$(bindir)/$(program_prefix)php-cgi$(program_suffix)$(EXEEXT)
+	@$(LIBTOOL) --mode=install $(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)@CGIDIR@/$(program_prefix)php$(program_suffix)$(EXEEXT)
 	@echo "Installing PHP CGI man page:      $(INSTALL_ROOT)$(mandir)/man1/"
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man1
 	@$(INSTALL_DATA) sapi/cgi/php-cgi.1 $(INSTALL_ROOT)$(mandir)/man1/$(program_prefix)php-cgi$(program_suffix).1
