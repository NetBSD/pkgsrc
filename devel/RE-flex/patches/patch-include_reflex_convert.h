$NetBSD: patch-include_reflex_convert.h,v 1.1 2024/03/21 20:44:40 wiz Exp $

fix doxygen errors

--- include/reflex/convert.h.orig	2024-03-11 17:59:51.000000000 +0000
+++ include/reflex/convert.h
@@ -122,8 +122,8 @@ namespace convert_flag {
 /// - `x` for `\xXX` 8-bit character encoding in hexadecimal
 /// - `y` for `\y` word boundary
 /// - `z` for `\z` end of input anchor
-/// - ``` for `\`` begin of input anchor
-/// - `'` for `\'` end of input anchor
+/// - \c \` for \c \\\` begin of input anchor
+/// - \c ' for \c \\' end of input anchor
 /// - `<` for `\<` left word boundary
 /// - `>` for `\>` right word boundary
 /// - `A` for `\A` begin of input anchor
@@ -144,7 +144,7 @@ namespace convert_flag {
 /// - '1' to '9' for backreferences (not applicable to lexer specifications)
 ///
 /// Note that 'p' is a special case to support Unicode-based matchers that
-/// natively support UTF8 patterns and Unicode classes \p{C}, \P{C}, \w, \W,
+/// natively support UTF8 patterns and Unicode classes \\p{C}, \P{C}, \w, \W,
 /// \d, \D, \l, \L, \u, \U, \N, and \x{X}.  Basically, 'p' prevents conversion
 /// of Unicode patterns to UTF8.  This special case does not support {NAME}
 /// expansions in bracket lists such as [a-z||{upper}] and {lower}{+}{upper}
