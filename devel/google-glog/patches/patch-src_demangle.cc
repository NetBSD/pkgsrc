$NetBSD: patch-src_demangle.cc,v 1.1 2013/07/18 12:01:29 joerg Exp $

--- src/demangle.cc.orig	2012-01-12 08:40:58.000000000 +0000
+++ src/demangle.cc
@@ -167,7 +167,7 @@ static size_t StrLen(const char *str) {
 // Returns true if "str" has at least "n" characters remaining.
 static bool AtLeastNumCharsRemaining(const char *str, int n) {
   for (int i = 0; i < n; ++i) {
-    if (str == '\0') {
+    if (str[i] == '\0') {
       return false;
     }
   }
@@ -223,7 +223,7 @@ static bool ParseTwoCharToken(State *sta
 // Returns true and advances "mangled_cur" if we find any character in
 // "char_class" at "mangled_cur" position.
 static bool ParseCharClass(State *state, const char *char_class) {
-  if (state->mangled_cur == '\0') {
+  if (state->mangled_cur == NULL) {
     return false;
   }
   const char *p = char_class;
