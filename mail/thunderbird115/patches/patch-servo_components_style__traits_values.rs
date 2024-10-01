$NetBSD: patch-servo_components_style__traits_values.rs,v 1.1 2024/10/01 14:21:38 ryoon Exp $

Bug 1912663 - Fix some build issues with cbindgen 0.27. r=firefox-style-system-reviewers,zrhoffman

It updates serde and syn and they are more strict. In particular, syn 2
doesn't parse the rust 2015 syntax where try is not a keyword, and serde
rejects duplicate keys.

Differential Revision: https://phabricator.services.mozilla.com/D219025

--- servo/components/style_traits/values.rs.orig	2024-08-19 19:21:51.000000000 +0000
+++ servo/components/style_traits/values.rs
@@ -388,11 +388,11 @@ impl Separator for Space {
     where
         F: for<'tt> FnMut(&mut Parser<'i, 'tt>) -> Result<T, ParseError<'i, E>>,
     {
-        input.skip_whitespace(); // Unnecessary for correctness, but may help try() rewind less.
+        input.skip_whitespace(); // Unnecessary for correctness, but may help try_parse() rewind less.
         let mut results = vec![parse_one(input)?];
         loop {
-            input.skip_whitespace(); // Unnecessary for correctness, but may help try() rewind less.
-            if let Ok(item) = input.try(&mut parse_one) {
+            input.skip_whitespace(); // Unnecessary for correctness, but may help try_parse() rewind less.
+            if let Ok(item) = input.try_parse(&mut parse_one) {
                 results.push(item);
             } else {
                 return Ok(results);
@@ -413,14 +413,14 @@ impl Separator for CommaWithSpace {
     where
         F: for<'tt> FnMut(&mut Parser<'i, 'tt>) -> Result<T, ParseError<'i, E>>,
     {
-        input.skip_whitespace(); // Unnecessary for correctness, but may help try() rewind less.
+        input.skip_whitespace(); // Unnecessary for correctness, but may help try_parse() rewind less.
         let mut results = vec![parse_one(input)?];
         loop {
-            input.skip_whitespace(); // Unnecessary for correctness, but may help try() rewind less.
+            input.skip_whitespace(); // Unnecessary for correctness, but may help try_parse() rewind less.
             let comma_location = input.current_source_location();
-            let comma = input.try(|i| i.expect_comma()).is_ok();
-            input.skip_whitespace(); // Unnecessary for correctness, but may help try() rewind less.
-            if let Ok(item) = input.try(&mut parse_one) {
+            let comma = input.try_parse(|i| i.expect_comma()).is_ok();
+            input.skip_whitespace(); // Unnecessary for correctness, but may help try_parse() rewind less.
+            if let Ok(item) = input.try_parse(&mut parse_one) {
                 results.push(item);
             } else if comma {
                 return Err(comma_location.new_unexpected_token_error(Token::Comma));
