$NetBSD: patch-util_cairo-trace_trace.c,v 1.2 2022/04/07 10:57:57 riastradh Exp $

Fix ctype(3) abuse.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/309

--- util/cairo-trace/trace.c.orig	2018-10-16 17:03:13.000000000 +0000
+++ util/cairo-trace/trace.c
@@ -564,7 +564,7 @@ _trace_dtostr (char *buffer, size_t size
 	if (*p == '+' || *p == '-')
 	    p++;
 
-	while (isdigit (*p))
+	while (isdigit ((unsigned char)*p))
 	    p++;
 
 	if (strncmp (p, decimal_point, decimal_point_len) == 0)
@@ -584,7 +584,7 @@ _trace_dtostr (char *buffer, size_t size
     if (*p == '+' || *p == '-')
 	p++;
 
-    while (isdigit (*p))
+    while (isdigit ((unsigned char)*p))
 	p++;
 
     if (strncmp (p, decimal_point, decimal_point_len) == 0) {
@@ -650,7 +650,7 @@ _trace_vprintf (const char *fmt, va_list
 	    f++;
         }
 
-	while (isdigit (*f))
+	while (isdigit ((unsigned char)*f))
 	    f++;
 
 	length_modifier = 0;
@@ -1848,7 +1848,7 @@ _encode_string_literal (char *out, int m
 	    max -= 2;
 	    break;
 	default:
-	    if (isprint (c) || isspace (c)) {
+	    if (isprint ((unsigned char)c) || isspace ((unsigned char)c)) {
 		*out++ = c;
 	    } else {
 		int octal = 0;
@@ -1918,7 +1918,7 @@ ESCAPED_CHAR:
 	    _trace_printf ("\\%c", c);
 	    break;
 	default:
-	    if (isprint (c) || isspace (c)) {
+	    if (isprint ((unsigned char)c) || isspace ((unsigned char)c)) {
 		_trace_printf ("%c", c);
 	    } else {
 		char buf[4] = { '\\' };
