$NetBSD: patch-vendor-cssparser_src_parser.rs,v 1.1 2019/10/04 01:45:42 tnn Exp $

error[E0506]: cannot assign to `self.input.cached_token` because it is borrowed
   --> src/parser.rs:572:17

https://github.com/servo/rust-cssparser/commit/3c98d22c5de3b696bf1fde2b6c90069812312aa6#diff-2c09afcdc3c420ab0678ba9b5e83959c

--- ../vendor/cssparser-0.24.0/src/parser.rs.orig	2017-12-11 12:41:06.000000000 +0000
+++ ../vendor/cssparser-0.24.0/src/parser.rs
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
-            }
-            _ => {
-                let new_token = self.input.tokenizer.next()
-                    .map_err(|()| self.new_basic_error(BasicParseErrorKind::EndOfInput))?;
-                self.input.cached_token = Some(CachedToken {
-                    token: new_token,
-                    start_position: token_start_position,
-                    end_state: self.input.tokenizer.state(),
-                });
-                token = self.input.cached_token_ref()
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
-        }
+            &cached_token.token
+        } else {
+            let new_token = self
+                .input
+                .tokenizer
+                .next()
+                .map_err(|()| self.new_basic_error(BasicParseErrorKind::EndOfInput))?;
+            self.input.cached_token = Some(CachedToken {
+                token: new_token,
+                start_position: token_start_position,
+                end_state: self.input.tokenizer.state(),
+            });
+            self.input.cached_token_ref()
+        };
 
         if let Some(block_type) = BlockType::opening(token) {
             self.at_start_of = Some(block_type);
