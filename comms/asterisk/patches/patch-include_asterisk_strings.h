$NetBSD: patch-include_asterisk_strings.h,v 1.1 2013/06/14 04:26:55 jnemeth Exp $

--- include/asterisk/strings.h.orig	2013-01-09 20:07:07.000000000 +0000
+++ include/asterisk/strings.h
@@ -947,7 +947,7 @@ char *ast_tech_to_upper(char *dev_str),
 	}
 
 	for (pos = dev_str; *pos && *pos != '/'; pos++) {
-		*pos = toupper(*pos);
+		*pos = toupper((unsigned char)*pos);
 	}
 	return dev_str;
 }
@@ -1006,7 +1006,7 @@ static force_inline int attribute_pure a
 	int hash = 5381;
 
 	while (*str) {
-		hash = hash * 33 ^ tolower(*str++);
+		hash = hash * 33 ^ tolower((unsigned char)*str++);
 	}
 
 	return abs(hash);
