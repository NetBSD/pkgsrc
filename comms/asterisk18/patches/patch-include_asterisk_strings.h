$NetBSD: patch-include_asterisk_strings.h,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- include/asterisk/strings.h.orig	2018-05-01 20:12:26.000000000 +0000
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
@@ -1265,7 +1265,7 @@ static force_inline char *attribute_pure
 	}
 
 	for (; *str; ++str) {
-		*str = tolower(*str);
+		*str = tolower((unsigned char)*str);
 	}
 
 	return str_orig;
@@ -1286,7 +1286,7 @@ static force_inline char *attribute_pure
 	}
 
 	for (; *str; ++str) {
-		*str = toupper(*str);
+		*str = toupper((unsigned char)*str);
 	}
 
 	return str_orig;
