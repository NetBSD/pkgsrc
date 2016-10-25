$NetBSD: patch-include_asterisk_strings.h,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- include/asterisk/strings.h.orig	2015-10-09 21:48:48.000000000 +0000
+++ include/asterisk/strings.h
@@ -1159,7 +1159,7 @@ char *ast_tech_to_upper(char *dev_str),
 	}
 
 	for (pos = dev_str; *pos && *pos != '/'; pos++) {
-		*pos = toupper(*pos);
+		*pos = toupper((unsigned char)*pos);
 	}
 	return dev_str;
 }
@@ -1218,7 +1218,7 @@ static force_inline int attribute_pure a
 	int hash = 5381;
 
 	while (*str) {
-		hash = hash * 33 ^ tolower(*str++);
+		hash = hash * 33 ^ tolower((unsigned char)*str++);
 	}
 
 	return abs(hash);
