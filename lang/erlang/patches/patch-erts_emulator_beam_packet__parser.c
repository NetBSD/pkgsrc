$NetBSD: patch-erts_emulator_beam_packet__parser.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/beam/packet_parser.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/beam/packet_parser.c
@@ -46,9 +46,9 @@ static int my_strncasecmp(const char *s1
 {
     int i;
 
-    for (i=0;i<n-1 && s1[i] && s2[i] && toupper(s1[i]) == toupper(s2[i]);++i)
+    for (i=0;i<n-1 && s1[i] && s2[i] && toupper((unsigned char)s1[i]) == toupper((unsigned char)s2[i]);++i)
 	;
-    return (toupper(s1[i]) - toupper(s2[i]));
+    return (toupper((unsigned char)s1[i]) - toupper((unsigned char)s2[i]));
 }
 	
 
@@ -551,7 +551,7 @@ http_parse_absoluteURI(PacketHttpURI* ur
       if (sys_memrchr(uri_ptr, ':', uri_len) == v + 1) {
         // Skip over `]:`
         v = v + 2;
-        while(n && isdigit((int) *v)) {
+        while(n && isdigit((unsigned char) *v)) {
             port = port*10 + (*v - '0');
             n--;
             v++;
@@ -568,7 +568,7 @@ http_parse_absoluteURI(PacketHttpURI* ur
         n = uri_len - (n+1);
         // Skip over port delimiter `:`
         p++;
-        while(n && isdigit((int) *p)) {
+        while(n && isdigit((unsigned char) *p)) {
             port = port*10 + (*p - '0');
             n--;
             p++;
@@ -684,7 +684,7 @@ int packet_parse_http(const char* buf, i
             ptr += 5;
             n -= 5;
             p0 = ptr;
-            while (n && isdigit((int) *ptr)) {
+            while (n && isdigit((unsigned char) *ptr)) {
                 major = 10*major + (*ptr - '0');
                 ptr++;
                 n--;
@@ -694,7 +694,7 @@ int packet_parse_http(const char* buf, i
             ptr++;
             n--;
             p0 = ptr;
-            while (n && isdigit((int) *ptr)) {
+            while (n && isdigit((unsigned char) *ptr)) {
                 minor = 10*minor + (*ptr - '0');
                 ptr++;
                 n--;
@@ -706,7 +706,7 @@ int packet_parse_http(const char* buf, i
             }
             if (ptr==p0) return -1;
             
-            while (n && isdigit((int) *ptr)) {
+            while (n && isdigit((unsigned char) *ptr)) {
                 status = 10*status + (*ptr - '0');
                 ptr++;
                 n--;
@@ -772,7 +772,7 @@ int packet_parse_http(const char* buf, i
             n   -= 5;
 
             p0 = ptr;
-            while (n && isdigit((int) *ptr)) {
+            while (n && isdigit((unsigned char) *ptr)) {
                 major = 10*major + (*ptr - '0');
                 ptr++;
                 n--;
@@ -782,7 +782,7 @@ int packet_parse_http(const char* buf, i
             ptr++;
             n--;
             p0 = ptr;
-            while (n && isdigit((int) *ptr)) {
+            while (n && isdigit((unsigned char) *ptr)) {
                 minor = 10*minor + (*ptr - '0');
                 ptr++;
                 n--;
@@ -814,14 +814,14 @@ int packet_parse_http(const char* buf, i
             if (name_len < HTTP_MAX_NAME_LEN) {
                 int c = *ptr;
                 if (up) {
-                    if (islower(c)) {
-                        c = toupper(c);
+                    if (islower((unsigned char)c)) {
+                        c = toupper((unsigned char)c);
                     }
                     up = 0;
                 }
                 else {
-                    if (isupper(c))
-                        c = tolower(c);
+                    if (isupper((unsigned char)c))
+                        c = tolower((unsigned char)c);
                     else if (c == '-')
                         up = 1;
                 }                            
