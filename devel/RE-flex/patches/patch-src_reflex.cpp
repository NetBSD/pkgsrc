$NetBSD: patch-src_reflex.cpp,v 1.1 2024/03/21 20:44:40 wiz Exp $

fix doxygen errors

--- src/reflex.cpp.orig	2024-03-17 20:54:34.000000000 +0000
+++ src/reflex.cpp
@@ -194,8 +194,8 @@ static const char *options_table[] = {
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
@@ -216,7 +216,7 @@ static const char *options_table[] = {
 /// - '1' to '9' for backreferences (not applicable to lexer specifications)
 ///
 /// Note that 'p' is a special case to support Unicode-based matchers that
-/// natively support UTF8 patterns and Unicode classes \p{C}, \P{C}, \w, \W,
+/// natively support UTF8 patterns and Unicode classes \\p{C}, \P{C}, \w, \W,
 /// \d, \D, \l, \L, \u, \U, \N, and \x{X}.  Basically, 'p' prevents conversion
 /// of Unicode patterns to UTF8.  This special case does not support {NAME}
 /// expansions in bracket lists such as [a-z||{upper}] and {lower}{+}{upper}
@@ -1915,7 +1915,7 @@ void Reflex::write_prelude()
     *out << "\n// --perf-report option requires a timer:\n#include <reflex/timer.h>\n";
 }
 
-/// Write Flex-compatible #defines to lex.yy.cpp
+/// Write Flex-compatible \#defines to lex.yy.cpp
 void Reflex::write_defines()
 {
   if (!out->good())
