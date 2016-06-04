$NetBSD: patch-sapi_cli_Makefile.frag,v 1.2.2.2 2016/06/04 19:56:36 bsiegert Exp $

Needed on NetBSD with PaX MPROTEXT, otherwise core dump with:
#1  0x00000000004d0d87 in _pcre_jit_exec ()
#2  0x00000000004a53f1 in php_pcre_exec ()
https://bugs.php.net/bug.php?id=72281

--- sapi/cli/Makefile.frag.orig	2016-04-28 18:12:27.000000000 +0000
+++ sapi/cli/Makefile.frag
@@ -2,6 +2,9 @@ cli: $(SAPI_CLI_PATH)
 
 $(SAPI_CLI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_BINARY_OBJS) $(PHP_CLI_OBJS)
 	$(BUILD_CLI)
+	@if test -f /usr/sbin/paxctl; then \
+		paxctl +m $(SAPI_CLI_PATH); \
+	fi
 
 install-cli: $(SAPI_CLI_PATH)
 	@echo "Installing PHP CLI binary:        $(INSTALL_ROOT)$(bindir)/"
