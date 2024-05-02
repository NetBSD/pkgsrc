$NetBSD: patch-src_format.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/format.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/format.cc
@@ -109,7 +109,7 @@ namespace {
 
       // Don't gobble up any whitespace
       const char * base = p;
-      while (p >= base && std::isspace(*p))
+      while (p >= base && std::isspace(static_cast<unsigned char>(*p)))
         p--;
     }
     return expr;
@@ -183,7 +183,7 @@ format_t::element_t * format_t::parse_el
     }
 
     std::size_t num = 0;
-    while (*p && std::isdigit(*p)) {
+    while (*p && std::isdigit(static_cast<unsigned char>(*p))) {
       num *= 10;
       num += static_cast<std::size_t>(*p++ - '0');
     }
@@ -192,7 +192,7 @@ format_t::element_t * format_t::parse_el
     if (*p == '.') {
       ++p;
       num = 0;
-      while (*p && std::isdigit(*p)) {
+      while (*p && std::isdigit(static_cast<unsigned char>(*p))) {
         num *= 10;
         num += static_cast<std::size_t>(*p++ - '0');
       }
@@ -201,7 +201,7 @@ format_t::element_t * format_t::parse_el
         current->min_width = current->max_width;
     }
 
-    if (std::isalpha(*p)) {
+    if (std::isalpha(static_cast<unsigned char>(*p))) {
       bool found = false;
       for (std::size_t i = 0; i < (sizeof(single_letter_mappings) /
                                    sizeof(format_mapping_t)); i++) {
@@ -210,7 +210,7 @@ format_t::element_t * format_t::parse_el
           for (const char * ptr = single_letter_mappings[i].expr; *ptr;) {
             if (*ptr == '$') {
               const char * beg = ++ptr;
-              while (*ptr && std::isalpha(*ptr))
+              while (*ptr && std::isalpha(static_cast<unsigned char>(*ptr)))
                 ++ptr;
               string::size_type klen = static_cast<string::size_type>(ptr - beg);
               string keyword(beg, 0, klen);
@@ -250,12 +250,13 @@ format_t::element_t * format_t::parse_el
           throw_(format_error, _("Prior field reference, but no template"));
 
         p++;
-        if (*p == '0' || (! std::isdigit(*p) &&
+        if (*p == '0' || (! std::isdigit(static_cast<unsigned char>(*p)) &&
                           *p != 'A' && *p != 'B' && *p != 'C' &&
                           *p != 'D' && *p != 'E' && *p != 'F'))
           throw_(format_error, _("%$ field reference must be a digit from 1-9"));
 
-        int         index     = std::isdigit(*p) ? *p - '0' : (*p - 'A' + 10);
+        int         index     = std::isdigit(static_cast<unsigned char>(*p))
+          ? *p - '0' : (*p - 'A' + 10);
         element_t * tmpl_elem = tmpl->elements.get();
 
         for (int i = 1; i < index && tmpl_elem; i++) {
@@ -630,7 +631,8 @@ string format_t::truncate(const unistrin
           if (adjust > 0) {
             DEBUG("format.abbrev",
                   "Reducing segment " << ++index << " by " << adjust << " chars");
-            while (std::isspace((*x)[*i - adjust - 1]) && adjust < *i) {
+            while (std::isspace(static_cast<unsigned char>(
+                (*x)[*i - adjust - 1])) && adjust < *i) {
               DEBUG("format.abbrev",
                     "Segment ends in whitespace, adjusting down");
               ++adjust;
