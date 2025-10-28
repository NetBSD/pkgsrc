$NetBSD: patch-src_bin_epp_cpplib.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/bin/epp/cpplib.c.orig	2013-11-05 11:37:07.000000000 +0000
+++ src/bin/epp/cpplib.c
@@ -2899,7 +2899,7 @@ macroexpand(cpp_reader * pfile, HASHNODE
 			    /* Escape these chars */
 			    if (c == '\"' || (in_string && c == '\\'))
 			       CPP_PUTC(pfile, '\\');
-			    if (isprint(c))
+			    if (isprint((unsigned char)c))
 			       CPP_PUTC(pfile, c);
 			    else
 			      {
@@ -4840,7 +4840,7 @@ cpp_get_token(cpp_reader * pfile)
 	  case '.':
 	     NEWLINE_FIX;
 	     c2 = PEEKC();
-	     if (isdigit(c2))
+	     if (isdigit((unsigned char)c2))
 	       {
 		  CPP_RESERVE(pfile, 2);
 		  CPP_PUTC_Q(pfile, '.');
