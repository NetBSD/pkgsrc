$NetBSD: patch-ext_phar_Makefile.frag,v 1.2.4.1 2015/06/13 10:46:49 tron Exp $

--- ext/phar/Makefile.frag.orig	2015-06-10 12:26:49.000000000 +0000
+++ ext/phar/Makefile.frag
@@ -18,7 +18,7 @@ PHP_PHARCMD_EXECUTABLE = ` \
 	else \
 		$(top_srcdir)/build/shtool echo -n -- "$(PHP_EXECUTABLE)"; \
 	fi;`
-PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(INSTALL_ROOT)$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
+PHP_PHARCMD_BANG = `$(top_srcdir)/build/shtool echo -n -- "$(bindir)/$(program_prefix)php$(program_suffix)$(EXEEXT)";`
 
 $(builddir)/phar/phar.inc: $(srcdir)/phar/phar.inc
 	-@test -d $(builddir)/phar || mkdir $(builddir)/phar
