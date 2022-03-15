$NetBSD: patch-crates_ide_completion_src_context.rs,v 1.1 2022/03/15 05:59:41 adam Exp $

For for pre-1.59.0.

--- crates/ide_completion/src/context.rs.orig	2022-03-15 05:54:01.000000000 +0000
+++ crates/ide_completion/src/context.rs
@@ -747,7 +747,9 @@ impl<'a> CompletionContext<'a> {
                 it.syntax().text_range().end() == syntax_element.text_range().end()
             });
 
-        (self.expected_type, self.expected_name) = self.expected_type_and_name();
+        let (expected_type, expected_name) = self.expected_type_and_name();
+        self.expected_type = expected_type;
+        self.expected_name = expected_name;
 
         // Overwrite the path kind for derives
         if let Some((original_file, file_with_fake_ident, offset)) = derive_ctx {
