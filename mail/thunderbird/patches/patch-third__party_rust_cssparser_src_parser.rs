$NetBSD: patch-third__party_rust_cssparser_src_parser.rs,v 1.1 2019/10/11 02:02:04 kamil Exp $

esr68 branch fails to build with rust 1.38
https://bugzilla.mozilla.org/show_bug.cgi?id=1585099

Cherry-pick patch from:
https://marc.info/?l=openbsd-ports&m=156984549605237&w=2

--- third_party/rust/cssparser/src/parser.rs.orig	2019-10-11 00:53:23.250060488 +0000
+++ third_party/rust/cssparser/src/parser.rs
@@ -567,28 +567,35 @@ impl<'i: 't, 't> Parser<'i, 't> {
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
+
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
