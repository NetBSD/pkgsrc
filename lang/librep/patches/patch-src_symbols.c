$NetBSD: patch-src_symbols.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/symbols.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/symbols.c
@@ -207,7 +207,7 @@ symbol_print(repv strm, repv obj)
 	    break;
 
 	default:
-	    if (iscntrl (c))
+	    if (iscntrl ((unsigned char)c))
 		*out++ = '\\';
 	    break;
 	}
