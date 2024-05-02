$NetBSD: patch-src_textual.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/textual.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/textual.cc
@@ -340,7 +340,8 @@ std::streamsize instance_t::read_line(ch
         --len;
     }
 
-    while (len > 0 && std::isspace(line[len - 1])) // strip trailing whitespace
+    // strip trailing whitespace
+    while (len > 0 && std::isspace(static_cast<unsigned char>(line[len - 1])))
       line[--len] = '\0';
 
     return len;
@@ -355,7 +356,7 @@ void instance_t::read_next_directive(boo
   if (len == 0 || line == NULL)
     return;
 
-  if (! std::isspace(line[0]))
+  if (! std::isspace(static_cast<unsigned char>(line[0])))
     error_flag = false;
 
   switch (line[0]) {
@@ -615,12 +616,16 @@ void instance_t::automated_xact_directiv
         item->pos->end_line++;
       }
       else if ((remlen > 7 && *p == 'a' &&
-                std::strncmp(p, "assert", 6) == 0 && std::isspace(p[6])) ||
+                std::strncmp(p, "assert", 6) == 0 &&
+                std::isspace(static_cast<unsigned char>(p[6]))) ||
                (remlen > 6 && *p == 'c' &&
-                std::strncmp(p, "check", 5) == 0 && std::isspace(p[5])) ||
+                std::strncmp(p, "check", 5) == 0 &&
+                std::isspace(static_cast<unsigned char>(p[5]))) ||
                (remlen > 5 && *p == 'e' &&
-                ((std::strncmp(p, "expr", 4) == 0 && std::isspace(p[4])) ||
-                 (std::strncmp(p, "eval", 4) == 0 && std::isspace(p[4]))))) {
+                ((std::strncmp(p, "expr", 4) == 0 &&
+                  std::isspace(static_cast<unsigned char>(p[4]))) ||
+                 (std::strncmp(p, "eval", 4) == 0 &&
+                  std::isspace(static_cast<unsigned char>(p[4])))))) {
         const char c = *p;
         p = skip_ws(&p[*p == 'a' ? 6 : (*p == 'c' ? 5 : 4)]);
         if (! ae->check_exprs)
@@ -1015,7 +1020,7 @@ void instance_t::alias_directive(char * 
 {
   if (char * e = std::strchr(line, '=')) {
     char * z = e - 1;
-    while (std::isspace(*z))
+    while (std::isspace(static_cast<unsigned char>(*z)))
       *z-- = '\0';
     *e++ = '\0';
     e = skip_ws(e);
@@ -1234,7 +1239,7 @@ void instance_t::python_directive(char *
     if (read_line(line) > 0) {
       if (! indent) {
         const char * p = line;
-        while (*p && std::isspace(*p)) {
+        while (*p && std::isspace(static_cast<unsigned char>(*p))) {
           ++indent;
           ++p;
         }
@@ -1242,7 +1247,7 @@ void instance_t::python_directive(char *
 
       const char * p = line;
       for (std::size_t i = 0; i < indent; i++) {
-        if (std::isspace(*p))
+        if (std::isspace(static_cast<unsigned char>(*p)))
           ++p;
         else
           break;
@@ -1473,7 +1478,7 @@ post_t * instance_t::parse_post(char *  
   char * next = next_element(p, true);
   char * e = p + std::strlen(p);
 
-  while (e > p && std::isspace(*(e - 1)))
+  while (e > p && std::isspace(static_cast<unsigned char>(*(e - 1))))
     e--;
 
   if ((*p == '[' && *(e - 1) == ']') || (*p == '(' && *(e - 1) == ')')) {
@@ -1884,7 +1889,7 @@ xact_t * instance_t::parse_xact(char *  
       }
       else if (*p == ';' && (tabs > 0 || spaces > 1)) {
         char *q = p - 1;
-        while (q > next && std::isspace(*q))
+        while (q > next && std::isspace(static_cast<unsigned char>(*q)))
           --q;
         if (q >= next)
           *(q + 1) = '\0';
@@ -1937,11 +1942,14 @@ xact_t * instance_t::parse_xact(char *  
       item->pos->end_line++;
     }
     else if ((remlen > 7 && *p == 'a' &&
-              std::strncmp(p, "assert", 6) == 0 && std::isspace(p[6])) ||
+              std::strncmp(p, "assert", 6) == 0 &&
+              std::isspace(static_cast<unsigned char>(p[6]))) ||
              (remlen > 6 && *p == 'c' &&
-              std::strncmp(p, "check", 5) == 0 && std::isspace(p[5])) ||
+              std::strncmp(p, "check", 5) == 0 &&
+              std::isspace(static_cast<unsigned char>(p[5]))) ||
              (remlen > 5 && *p == 'e' &&
-              std::strncmp(p, "expr", 4) == 0 && std::isspace(p[4]))) {
+              std::strncmp(p, "expr", 4) == 0 &&
+              std::isspace(static_cast<unsigned char>(p[4])))) {
       const char c = *p;
       p = skip_ws(&p[*p == 'a' ? 6 : (*p == 'c' ? 5 : 4)]);
       expr_t expr(p);
