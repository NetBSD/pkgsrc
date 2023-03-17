$NetBSD: patch-libpkgconf_parser.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/parser.c.orig	2023-01-21 20:09:52.000000000 +0000
+++ libpkgconf/parser.c
@@ -44,7 +44,7 @@ pkgconf_parser_parse(FILE *f, void *data
 		lineno++;
 
 		p = readbuf;
-		while (*p && isspace((unsigned int)*p))
+		while (*p && isspace((unsigned char)*p))
 			p++;
 		if (*p && p != readbuf)
 		{
@@ -53,13 +53,14 @@ pkgconf_parser_parse(FILE *f, void *data
 			warned_key_whitespace = true;
 		}
 		key = p;
-		while (*p && (isalpha((unsigned int)*p) || isdigit((unsigned int)*p) || *p == '_' || *p == '.'))
+		while (*p && (isalpha((unsigned char)*p) || isdigit((unsigned char)*p) || *p == '_' || *p == '.'))
 			p++;
 
-		if (!isalpha((unsigned int)*key) && !isdigit((unsigned int)*p))
+		if (!isalpha((unsigned char)*key) &&
+		    !isdigit((unsigned char)*p))
 			continue;
 
-		while (*p && isspace((unsigned int)*p))
+		while (*p && isspace((unsigned char)*p))
 		{
 			if (!warned_key_whitespace)
 			{
@@ -80,12 +81,12 @@ pkgconf_parser_parse(FILE *f, void *data
 			p++;
 		}
 
-		while (*p && isspace((unsigned int)*p))
+		while (*p && isspace((unsigned char)*p))
 			p++;
 
 		value = p;
 		p = value + (strlen(value) - 1);
-		while (*p && isspace((unsigned int) *p) && p > value)
+		while (*p && isspace((unsigned char) *p) && p > value)
 		{
 			if (!warned_value_whitespace && op == '=')
 			{
