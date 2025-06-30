$NetBSD: patch-external_nmea_tok.c,v 1.1 2025/06/30 22:51:46 gdt Exp $

Fix ctype abuse.

Not yet filed upstream.

--- external/nmea/tok.c.orig	2025-06-30 17:42:24.183818957 +0000
+++ external/nmea/tok.c
@@ -179,7 +179,7 @@ int nmea_scanf( const char *buff, int bu
 
       case NMEA_TOKS_WIDTH:
       {
-        if ( isdigit( *format ) )
+        if ( isdigit( (unsigned char) *format ) )
           break;
 
         tok_type = NMEA_TOKS_TYPE;
