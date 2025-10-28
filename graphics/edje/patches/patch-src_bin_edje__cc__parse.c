$NetBSD: patch-src_bin_edje__cc__parse.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/bin/edje_cc_parse.c.orig	2013-07-30 14:42:43.000000000 +0000
+++ src/bin/edje_cc_parse.c
@@ -306,7 +306,7 @@ next_token(char *p, char *end, char **ne
 	       {
 		  if (!in_quote)
 		    {
-		       if (!isspace(*p))
+		       if (!isspace((unsigned char)*p))
 			 {
 			    if (*p == '"')
 			      {
@@ -353,7 +353,7 @@ next_token(char *p, char *end, char **ne
 
 		       /* check for end-of-token */
 		       if (
-			   (isspace(*p)) ||
+			   (isspace((unsigned char)*p)) ||
 			   ((*delim) && (!isdelim(*p))) ||
 			   (isdelim(*p))
 			   )
