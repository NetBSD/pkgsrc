$NetBSD: patch-erlang.mk,v 1.2 2026/02/07 00:40:22 gdt Exp $

Regenerated erlang.mk from Erlang 27 support, from https://github.com/ninenines/erlang.mk
Stripped -Werror.

--- erlang.mk.orig	2025-11-20 14:50:28.000000000 +0000
+++ erlang.mk
@@ -1461,7 +1461,7 @@ endif
 
 # Configuration.
 
-ERLC_OPTS ?= -Werror +debug_info +warn_export_vars +warn_shadow_vars \
+ERLC_OPTS ?= +debug_info +warn_export_vars +warn_shadow_vars \
 	+warn_obsolete_guard # +bin_opt_info +warn_export_all +warn_missing_spec
 COMPILE_FIRST ?=
 COMPILE_FIRST_PATHS = $(addprefix src/,$(addsuffix .erl,$(COMPILE_FIRST)))
