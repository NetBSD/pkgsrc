$NetBSD: patch-main_spprintf.c,v 1.1 2011/03/21 16:34:28 taca Exp $

--- main/spprintf.c.orig	2010-01-03 09:23:27.000000000 +0000
+++ main/spprintf.c
@@ -282,10 +282,6 @@ static void xbuf_format_converter(smart_
 
 				/*
 				 * Check if a precision was specified
-				 *
-				 * XXX: an unreasonable amount of precision may be specified
-				 * resulting in overflow of num_buf. Currently we
-				 * ignore this possibility.
 				 */
 				if (*fmt == '.') {
 					adjust_precision = YES;
@@ -299,6 +295,10 @@ static void xbuf_format_converter(smart_
 							precision = 0;
 					} else
 						precision = 0;
+
+					if (precision > FORMAT_CONV_MAX_PRECISION) {
+						precision = FORMAT_CONV_MAX_PRECISION;
+					}
 				} else
 					adjust_precision = NO;
 			} else
