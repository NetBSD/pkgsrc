$NetBSD: patch-menuselect_menuselect.c,v 1.1 2024/10/21 05:12:47 jnemeth Exp $

--- menuselect/menuselect.c.orig	2018-05-07 17:13:49.312815875 +0000
+++ menuselect/menuselect.c
@@ -1461,7 +1461,7 @@ static int generate_makedeps_file(void)
 				}
 
 				for (c = dep->name; *c; c++)
-					fputc(toupper(*c), f);
+					fputc(toupper((unsigned char)*c), f);
 				fputc(' ', f);
 			}
 			AST_LIST_TRAVERSE(&mem->uses, use, list) {
@@ -1477,7 +1477,7 @@ static int generate_makedeps_file(void)
 				}
 
 				for (c = use->name; *c; c++)
-					fputc(toupper(*c), f);
+					fputc(toupper((unsigned char)*c), f);
 				fputc(' ', f);
 			}
 
