$NetBSD: patch-crates_mbe_src_expander_transcriber.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/mbe/src/expander/transcriber.rs.orig	2022-02-14 08:17:53.000000000 +0000
+++ crates/mbe/src/expander/transcriber.rs
@@ -21,28 +21,28 @@ impl Bindings {
         }
 
         let mut b: &Binding =
-            self.inner.get(name).ok_or_else(|| binding_err!("could not find binding `{name}`"))?;
+            self.inner.get(name).ok_or_else(|| binding_err!("could not find binding `{}`", name))?;
         for nesting_state in nesting.iter_mut() {
             nesting_state.hit = true;
             b = match b {
                 Binding::Fragment(_) => break,
                 Binding::Nested(bs) => bs.get(nesting_state.idx).ok_or_else(|| {
                     nesting_state.at_end = true;
-                    binding_err!("could not find nested binding `{name}`")
+                    binding_err!("could not find nested binding `{}`", name)
                 })?,
                 Binding::Empty => {
                     nesting_state.at_end = true;
-                    return Err(binding_err!("could not find empty binding `{name}`"));
+                    return Err(binding_err!("could not find empty binding `{}`", name));
                 }
             };
         }
         match b {
             Binding::Fragment(it) => Ok(it),
             Binding::Nested(_) => {
-                Err(binding_err!("expected simple binding, found nested binding `{name}`"))
+                Err(binding_err!("expected simple binding, found nested binding `{}`", name))
             }
             Binding::Empty => {
-                Err(binding_err!("expected simple binding, found empty binding `{name}`"))
+                Err(binding_err!("expected simple binding, found empty binding `{}`", name))
             }
         }
     }
