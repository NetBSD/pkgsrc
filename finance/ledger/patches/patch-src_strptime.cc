$NetBSD: patch-src_strptime.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/strptime.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/strptime.cc
@@ -62,7 +62,9 @@ static const char* kMonthAbbr[] = {
 
 static const char* _parse_num(const char* s, int low, int high, int* value) {
   const char* p = s;
-  for (*value = 0; *p != NULL && isdigit(*p); ++p) {
+  for (*value = 0;
+       *p != NULL && isdigit(static_cast<unsigned char>(*p));
+       ++p) {
     *value = (*value) * 10 + static_cast<int>(*p) - static_cast<int>('0');
   }
 
@@ -177,7 +179,7 @@ static char* _strptime(const char *s, co
       // arbitrary whitespace.
       case 't':
       case 'n':
-        while (isspace(*s)) ++s;
+        while (isspace(static_cast<unsigned char>(*s))) ++s;
         break;
 
       // '%'.
