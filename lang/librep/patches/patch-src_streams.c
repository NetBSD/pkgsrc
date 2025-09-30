$NetBSD: patch-src_streams.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/streams.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/streams.c
@@ -479,7 +479,7 @@ rep_stream_read_esc (repv stream, int *c
 	c = '\a';
 	break;
     case '^':
-	c = toupper (rep_stream_getc (stream)) ^ 0x40;
+	c = toupper ((unsigned char)rep_stream_getc (stream)) ^ 0x40;
 	break;
     case '0':
     case '1':
@@ -510,12 +510,12 @@ rep_stream_read_esc (repv stream, int *c
 	while (1)
 	{
 	    *c_p = rep_stream_getc (stream);
-	    if (!isxdigit (*c_p))
+	    if (!isxdigit ((unsigned char)*c_p))
 		return c;
 	    if ((*c_p >= '0') && (*c_p <= '9'))
 		c = (c * 16) + (*c_p - '0');
 	    else
-		c = (c * 16) + (toupper (*c_p) - 'A') + 10;
+		c = (c * 16) + (toupper ((unsigned char)*c_p) - 'A') + 10;
 	}
     default:
 	c = *c_p;
@@ -971,7 +971,7 @@ Note that the FIELD-WIDTH and all flags 
 
 	    /* Now look for the field width */
 	parse_field_width:
-	    while(isdigit (c))
+	    while(isdigit ((unsigned char)c))
 	    {
 		field_width = field_width * 10 + (c - '0');
 		c = *fmt++;
@@ -981,7 +981,7 @@ Note that the FIELD-WIDTH and all flags 
 	    if (c == '.')
 	    {
 		c = *fmt++;
-		while (c && isdigit (c))
+		while (c && isdigit ((unsigned char)c))
 		{
 		    precision = precision * 10 + (c - '0');
 		    c = *fmt++;
