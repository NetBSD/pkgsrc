$NetBSD: patch-yjit_not__gmake.mk,v 1.1 2026/02/03 16:00:34 taca Exp $

Stop building YJIT_LIBS each time.

--- yjit/not_gmake.mk.orig	2025-02-14 21:25:54.000000000 +0000
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
 
