$NetBSD: patch-src_numbers.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/numbers.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/numbers.c
@@ -875,7 +875,7 @@ parse_integer_to_float (char *buf, unsig
     {
 	int d;
 	char c = *buf++;
-	d = toupper (c) - '0';
+	d = toupper ((unsigned char)c) - '0';
 	if (d < 0 || d >= MAP_SIZE)
 	    return rep_FALSE;
 	d = map [d];
@@ -966,7 +966,7 @@ rep_parse_number (char *buf, unsigned in
 		{
 		    int d;
 		    c = *buf++;
-		    d = toupper (c) - '0';
+		    d = toupper ((unsigned char)c) - '0';
 		    if (d < 0 || d >= MAP_SIZE)
 			goto error;
 		    d = map [d];
