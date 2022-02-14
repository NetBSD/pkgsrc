$NetBSD: patch-crates_mbe_src_expander_matcher.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/mbe/src/expander/matcher.rs.orig	2022-02-14 08:16:44.000000000 +0000
+++ crates/mbe/src/expander/matcher.rs
@@ -657,7 +657,7 @@ fn match_loop(pattern: &MetaTemplate, sr
 fn match_leaf(lhs: &tt::Leaf, src: &mut TtIter) -> Result<(), ExpandError> {
     let rhs = src
         .expect_leaf()
-        .map_err(|()| ExpandError::BindingError(format!("expected leaf: `{lhs}`").into()))?;
+        .map_err(|()| ExpandError::BindingError(format!("expected leaf: `{}`", lhs).into()))?;
     match (lhs, rhs) {
         (
             tt::Leaf::Punct(tt::Punct { char: lhs, .. }),
