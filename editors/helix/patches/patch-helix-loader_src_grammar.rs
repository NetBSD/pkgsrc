$NetBSD: patch-helix-loader_src_grammar.rs,v 1.4 2024/03/24 20:06:49 adam Exp $

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/grammar.rs.orig	2024-02-19 21:27:43.949172144 +0000
+++ helix-loader/src/grammar.rs
@@ -99,57 +99,6 @@ pub fn fetch_grammars() -> Result<()> {
     let mut grammars = get_grammar_configs()?;
     grammars.retain(|grammar| !matches!(grammar.source, GrammarSource::Local { .. }));
 
-    println!("Fetching {} grammars", grammars.len());
-    let results = run_parallel(grammars, fetch_grammar);
-
-    let mut errors = Vec::new();
-    let mut git_updated = Vec::new();
-    let mut git_up_to_date = 0;
-    let mut non_git = Vec::new();
-
-    for (grammar_id, res) in results {
-        match res {
-            Ok(FetchStatus::GitUpToDate) => git_up_to_date += 1,
-            Ok(FetchStatus::GitUpdated { revision }) => git_updated.push((grammar_id, revision)),
-            Ok(FetchStatus::NonGit) => non_git.push(grammar_id),
-            Err(e) => errors.push((grammar_id, e)),
-        }
-    }
-
-    non_git.sort_unstable();
-    git_updated.sort_unstable_by(|a, b| a.0.cmp(&b.0));
-
-    if git_up_to_date != 0 {
-        println!("{} up to date git grammars", git_up_to_date);
-    }
-
-    if !non_git.is_empty() {
-        println!("{} non git grammars", non_git.len());
-        println!("\t{:?}", non_git);
-    }
-
-    if !git_updated.is_empty() {
-        println!("{} updated grammars", git_updated.len());
-        // We checked the vec is not empty, unwrapping will not panic
-        let longest_id = git_updated.iter().map(|x| x.0.len()).max().unwrap();
-        for (id, rev) in git_updated {
-            println!(
-                "\t{id:width$} now on {rev}",
-                id = id,
-                width = longest_id,
-                rev = rev
-            );
-        }
-    }
-
-    if !errors.is_empty() {
-        let len = errors.len();
-        for (i, (grammar, error)) in errors.into_iter().enumerate() {
-            println!("Failure {}/{len}: {grammar} {error}", i + 1);
-        }
-        bail!("{len} grammars failed to fetch");
-    }
-
     Ok(())
 }
 
