$NetBSD: patch-include_strutils.h,v 1.4 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- include/strutils.h.orig	2024-07-04 07:54:41.223242118 +0000
+++ include/strutils.h
@@ -276,14 +276,14 @@ static inline const char *endswith(const
  */
 static inline const char *skip_space(const char *p)
 {
-	while (isspace(*p))
+	while (isspace((unsigned char)*p))
 		++p;
 	return p;
 }
 
 static inline const char *skip_blank(const char *p)
 {
-	while (isblank(*p))
+	while (isblank((unsigned char)*p))
 		++p;
 	return p;
 }
