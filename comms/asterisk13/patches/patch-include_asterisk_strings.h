$NetBSD: patch-include_asterisk_strings.h,v 1.2 2017/06/04 07:51:27 jnemeth Exp $

--- include/asterisk/strings.h.orig	2017-05-30 17:44:16.000000000 +0000
+++ include/asterisk/strings.h
@@ -1168,7 +1168,7 @@ char *ast_tech_to_upper(char *dev_str),
 	}
 
 	for (pos = dev_str; *pos && *pos != '/'; pos++) {
-		*pos = toupper(*pos);
+		*pos = toupper((unsigned char)*pos);
 	}
 	return dev_str;
 }
@@ -1244,7 +1244,7 @@ static force_inline int attribute_pure a
 	unsigned int hash = 5381;
 
 	while (*str) {
-		hash = hash * 33 ^ (unsigned char) tolower(*str++);
+		hash = hash * 33 ^ tolower((unsigned char)*str++);
 	}
 
 	return ast_str_hash_restrict(hash);
