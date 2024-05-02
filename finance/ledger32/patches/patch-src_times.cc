$NetBSD: patch-src_times.cc,v 1.1 2024/05/02 12:22:13 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/times.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/times.cc
@@ -1467,7 +1467,7 @@ date_parser_t::lexer_t::token_t date_par
     return tok;
   }
 
-  while (begin != end && std::isspace(*begin))
+  while (begin != end && std::isspace(static_cast<unsigned char>(*begin)))
     begin++;
 
   if (begin == end)
@@ -1486,9 +1486,11 @@ date_parser_t::lexer_t::token_t date_par
   // date using the typical date formats.  This allows not only dates like
   // "2009/08/01", but also dates that fit the user's --input-date-format,
   // assuming their format fits in one argument and begins with a digit.
-  if (std::isdigit(*begin)) {
+  if (std::isdigit(static_cast<unsigned char>(*begin))) {
     string::const_iterator i = begin;
-    for (i = begin; i != end && ! std::isspace(*i); i++) {}
+    for (i = begin;
+         i != end && ! std::isspace(static_cast<unsigned char>(*i));
+         i++) {}
     assert(i != begin);
 
     string possible_date(start, i);
@@ -1513,18 +1515,20 @@ date_parser_t::lexer_t::token_t date_par
   start = begin;
 
   string term;
-  bool alnum = std::isalnum(*begin);
-  for (; (begin != end && ! std::isspace(*begin) &&
-          ((alnum && static_cast<bool>(std::isalnum(*begin))) ||
-           (! alnum && ! static_cast<bool>(std::isalnum(*begin))))); begin++)
+  bool alnum = std::isalnum(static_cast<unsigned char>(*begin));
+  for (; (begin != end && ! std::isspace(static_cast<unsigned char>(*begin)) &&
+          ((alnum && static_cast<bool>(std::isalnum(
+             static_cast<unsigned char>(*begin)))) ||
+           (! alnum && ! static_cast<bool>(std::isalnum(
+             static_cast<unsigned char>(*begin)))))); begin++)
     term.push_back(*begin);
 
   if (! term.empty()) {
-    if (std::isdigit(term[0])) {
+    if (std::isdigit(static_cast<unsigned char>(term[0]))) {
       return token_t(token_t::TOK_INT,
                      token_t::content_t(lexical_cast<unsigned short>(term)));
     }
-    else if (std::isalpha(term[0])) {
+    else if (std::isalpha(static_cast<unsigned char>(term[0]))) {
       to_lower(term);
 
       if (optional<date_time::months_of_year> month =
