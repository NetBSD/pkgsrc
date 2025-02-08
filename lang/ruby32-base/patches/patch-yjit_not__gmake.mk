$NetBSD: patch-yjit_not__gmake.mk,v 1.1 2025/02/08 05:05:51 taca Exp $

Stop building YJIT_LIBS each time.

--- yjit/not_gmake.mk.orig	2024-10-30 09:47:11.000000000 +0000
+++ yjit/not_gmake.mk
@@ -3,11 +3,7 @@
 
 # Rebuild every time since we don't want to list Rust source
 # file dependencies.
-.PHONY: yjit-static-lib
-$(YJIT_LIBS): yjit-static-lib
-	$(empty)
-
-yjit-static-lib:
+$(YJIT_LIBS):
 	$(ECHO) 'building Rust YJIT (release mode)'
 	$(Q) $(RUSTC) $(YJIT_RUSTC_ARGS)
 
