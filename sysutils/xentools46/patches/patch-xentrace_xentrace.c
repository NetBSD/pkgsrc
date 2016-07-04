$NetBSD: patch-xentrace_xentrace.c,v 1.1.1.1 2016/07/04 07:30:51 jnemeth Exp $

--- xentrace/xentrace.c.orig	2016-02-09 14:44:19.000000000 +0000
+++ xentrace/xentrace.c
@@ -945,7 +945,7 @@ static int parse_cpumask_range(const cha
 {
     unsigned int a, b;
     int nmaskbits;
-    char c;
+    unsigned char c;
     int in_range;
     const char *s;
 
