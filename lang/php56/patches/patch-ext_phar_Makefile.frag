$NetBSD: patch-ext_phar_Makefile.frag,v 1.4 2025/02/08 02:57:59 taca Exp $

Set shbang for phar correctly.

--- ext/phar/Makefile.frag.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/phar/Makefile.frag
@@ -18,7 +18,7 @@ PHP_PHARCMD_EXECUTABLE = ` \
 	else \
 		$(top_srcdir)/build/shtool echo -n -- "$(PHP_EXECUTABLE)"; \
 	fi;`
-PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(INSTALL_ROOT)$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
+PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
 
 $(builddir)/phar/phar.inc: $(srcdir)/phar/phar.inc
 	-@test -d $(builddir)/phar || mkdir $(builddir)/phar
@@ -37,10 +37,9 @@ $(builddir)/phar.phar: $(builddir)/phar.
 
 install-pharcmd: pharcmd
 	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
-	$(INSTALL) $(builddir)/phar.phar $(INSTALL_ROOT)$(bindir)
-	-@rm -f $(INSTALL_ROOT)$(bindir)/phar
-	$(LN_S) -f phar.phar $(INSTALL_ROOT)$(bindir)/phar
+	$(INSTALL) $(builddir)/phar.phar $(INSTALL_ROOT)$(bindir)/phar$(PHP_VER).phar
+	-@rm -f $(INSTALL_ROOT)$(bindir)/phar$(PHP_VER)
+	$(LN_S) -f phar$(PHP_VER).phar $(INSTALL_ROOT)$(bindir)/phar$(PHP_VER)
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man1
-	@$(INSTALL_DATA) $(builddir)/phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar.1
-	@$(INSTALL_DATA) $(builddir)/phar.phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar.phar.1
-
+	@$(INSTALL_DATA) $(builddir)/phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar$(PHP_VER).1
+	@$(INSTALL_DATA) $(builddir)/phar.phar.1 $(INSTALL_ROOT)$(mandir)/man1/phar$(PHP_VER).phar.1
