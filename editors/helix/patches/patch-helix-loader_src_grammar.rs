$NetBSD: patch-helix-loader_src_grammar.rs,v 1.1 2022/04/02 09:36:15 nikita Exp $

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/grammar.rs.orig	2022-03-30 19:54:07 UTC
+++ helix-loader/src/grammar.rs
@@ -79,8 +79,7 @@ pub fn fetch_grammars() -> Result<()> {
     // We do not need to fetch local grammars.
     let mut grammars = get_grammar_configs()?;
     grammars.retain(|grammar| !matches!(grammar.source, GrammarSource::Local { .. }));
-
-    run_parallel(grammars, fetch_grammar, "fetch")
+    Ok(())
 }
 
 pub fn build_grammars() -> Result<()> {
