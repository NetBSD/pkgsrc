$NetBSD: patch-src_bin_edje__decc.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/bin/edje_decc.c.orig	2013-07-30 14:42:43.000000000 +0000
+++ src/bin/edje_decc.c
@@ -520,7 +520,7 @@ compiler_cmd_is_sane()
    for (ptr = c; ptr && *ptr; ptr++)
      {
 	/* only allow [a-z][A-Z][0-9]_- */
-	if ((!isalnum(*ptr)) && (*ptr != '_') && (*ptr != '-'))
+	if ((!isalnum((unsigned char)*ptr)) && (*ptr != '_') && (*ptr != '-'))
 	  {
 	     return 0;
 	  }
@@ -548,7 +548,7 @@ root_filename_is_sane()
 	   case '_': case '-':  case '.': case '/':
 	      break;
 	   default:
-	      if (!isalnum(*ptr))
+	      if (!isalnum((unsigned char)*ptr))
 		{
 		   return 0;
 		}
