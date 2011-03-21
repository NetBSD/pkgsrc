$NetBSD: patch-main_snprintf.c,v 1.1 2011/03/21 16:34:28 taca Exp $

--- main/snprintf.c.orig	2010-01-03 09:23:27.000000000 +0000
+++ main/snprintf.c
@@ -675,10 +675,6 @@ static int format_converter(register buf
 
 				/*
 				 * Check if a precision was specified
-				 *
-				 * XXX: an unreasonable amount of precision may be specified
-				 * resulting in overflow of num_buf. Currently we
-				 * ignore this possibility.
 				 */
 				if (*fmt == '.') {
 					adjust_precision = YES;
@@ -692,6 +688,10 @@ static int format_converter(register buf
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
