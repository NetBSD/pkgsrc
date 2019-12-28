$NetBSD: patch-third__party_rust_cssparser_src_parser.rs,v 1.1 2019/12/28 05:55:53 ryoon Exp $

* Partially backport for rust-1.39.0
  from https://phabricator.services.mozilla.com/D47796

--- third_party/rust/cssparser/src/parser.rs.orig	2019-09-01 13:09:43.000000000 +0000
+++ third_party/rust/cssparser/src/parser.rs
@@ -555,28 +555,34 @@ impl<'i: 't, 't> Parser<'i, 't> {
         }
 
         let token_start_position = self.input.tokenizer.position();
-        let token;
-        match self.input.cached_token {
-            Some(ref cached_token)
-            if cached_token.start_position == token_start_position => {
-                self.input.tokenizer.reset(&cached_token.end_state);
-                match cached_token.token {
-                    Token::Function(ref name) => self.input.tokenizer.see_function(name),
-                    _ => {}
-                }
-                token = &cached_token.token
+        let using_cached_token = self
+            .input
+            .cached_token
+            .as_ref()
+            .map_or(false, |cached_token| {
+                cached_token.start_position == token_start_position
+            });
+        let token = if using_cached_token {
+            let cached_token = self.input.cached_token.as_ref().unwrap();
+            self.input.tokenizer.reset(&cached_token.end_state);
+            match cached_token.token {
+                Token::Function(ref name) => self.input.tokenizer.see_function(name),
+                _ => {}
             }
-            _ => {
-                let new_token = self.input.tokenizer.next()
+            &cached_token.token
+        } else {
+            let new_token = self
+                .input
+                .tokenizer
+                .next()
                     .map_err(|()| self.new_basic_error(BasicParseErrorKind::EndOfInput))?;
                 self.input.cached_token = Some(CachedToken {
                     token: new_token,
                     start_position: token_start_position,
                     end_state: self.input.tokenizer.state(),
                 });
-                token = self.input.cached_token_ref()
-            }
-        }
+                self.input.cached_token_ref()
+        };
 
         if let Some(block_type) = BlockType::opening(token) {
             self.at_start_of = Some(block_type);
