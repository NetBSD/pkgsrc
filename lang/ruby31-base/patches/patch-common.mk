$NetBSD: patch-common.mk,v 1.1 2022/01/16 13:57:10 taca Exp $

* Do not try to download gem files.

--- common.mk.orig	2020-12-08 09:02:31.000000000 +0000
+++ common.mk
@@ -549,7 +549,7 @@ post-install-doc::
 	@$(NULLCMD)
 
 install-gem: pre-install-gem do-install-gem post-install-gem
-pre-install-gem:: prepare-gems pre-install-bin pre-install-lib pre-install-man
+pre-install-gem:: pre-install-bin pre-install-lib pre-install-man
 do-install-gem: $(PROGRAM) pre-install-gem
 	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=gem
 post-install-gem::
