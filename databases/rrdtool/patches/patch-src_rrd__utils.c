$NetBSD: patch-src_rrd__utils.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_utils.c~	2016-04-19 15:52:26.000000000 +0000
+++ src/rrd_utils.c
@@ -238,7 +238,7 @@ const char * rrd_scaled_duration (const 
     char * ep = NULL;
     unsigned long int value = strtoul(token, &ep, 10);
     /* account for -1 => UMAXLONG which is not what we want */
-    if (! isdigit(token[0]))
+    if (! isdigit((unsigned char)token[0]))
         return "value must be (suffixed) positive number";
     /* Catch an internal error before we inhibit scaling */
     if (0 == divisor)
