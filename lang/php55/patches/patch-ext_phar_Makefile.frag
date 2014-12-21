$NetBSD: patch-ext_phar_Makefile.frag,v 1.1.10.1 2014/12/21 16:19:40 tron Exp $

--- ext/phar/Makefile.frag.orig	2014-12-17 09:39:40.000000000 +0000
+++ ext/phar/Makefile.frag
@@ -18,7 +18,7 @@ PHP_PHARCMD_EXECUTABLE = ` \
 	else \
 		$(top_srcdir)/build/shtool echo -n -- "$(PHP_EXECUTABLE)"; \
 	fi;`
-PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(INSTALL_ROOT)$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
+PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
 
 $(builddir)/phar/phar.inc: $(srcdir)/phar/phar.inc
 	-@test -d $(builddir)/phar || mkdir $(builddir)/phar
@@ -39,7 +39,7 @@ install-pharcmd: pharcmd
 	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
 	$(INSTALL) $(builddir)/phar.phar $(INSTALL_ROOT)$(bindir)
 	-@rm -f $(INSTALL_ROOT)$(bindir)/phar
-	$(LN_S) -f $(INSTALL_ROOT)$(bindir)/phar.phar $(INSTALL_ROOT)$(bindir)/phar
+	$(LN_S) -f phar.phar $(INSTALL_ROOT)$(bindir)/phar
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man1
 	@$(INSTALL_DATA) $(builddir)/phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar.1
 	@$(INSTALL_DATA) $(builddir)/phar.phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar.phar.1
