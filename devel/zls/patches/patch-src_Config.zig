$NetBSD$

--- src/Config.zig.orig	2024-06-09 00:05:07.000000000 +0000
+++ src/Config.zig
@@ -19,7 +19,7 @@ build_on_save_step: []const u8 = "instal
 /// Whether to automatically fix errors on save. Currently supports adding and removing discards.
 enable_autofix: bool = false,
 
-/// Set level of semantic tokens. Partial only includes information that requires semantic analysis.
+/// Set level of semantic tokens. `partial` only includes information that requires semantic analysis.
 semantic_tokens: enum {
     none,
     partial,
