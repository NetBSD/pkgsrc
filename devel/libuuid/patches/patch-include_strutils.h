$NetBSD: patch-include_strutils.h,v 1.3 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- include/strutils.h.orig	2018-06-04 07:57:02.792445890 +0000
+++ include/strutils.h
@@ -162,14 +162,14 @@ static inline const char *endswith(const
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
