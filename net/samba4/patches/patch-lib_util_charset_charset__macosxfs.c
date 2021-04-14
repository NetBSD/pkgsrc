$NetBSD: patch-lib_util_charset_charset__macosxfs.c,v 1.1 2021/04/14 19:11:21 adam Exp $

DEBUG is undefined.

--- lib/util/charset/charset_macosxfs.c.orig	2021-04-14 09:58:53.000000000 +0000
+++ lib/util/charset/charset_macosxfs.c
@@ -137,7 +137,7 @@ static inline UniChar *set_ucbuffer_with
 /*
  * A simple hexdump function for debugging error conditions.
  */
-#define	debug_out(s)	DEBUG(0,(s))
+#define	debug_out(s) /* nothing */	
 
 #ifdef DEBUG_STRINGS
 
