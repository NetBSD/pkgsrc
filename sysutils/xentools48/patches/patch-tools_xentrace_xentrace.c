$NetBSD: patch-tools_xentrace_xentrace.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/xentrace/xentrace.c.orig	2016-02-09 14:44:19.000000000 +0000
+++ tools/xentrace/xentrace.c
@@ -945,7 +945,7 @@ static int parse_cpumask_range(const cha
 {
     unsigned int a, b;
     int nmaskbits;
-    char c;
+    unsigned char c;
     int in_range;
     const char *s;
 
