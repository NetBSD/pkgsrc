$NetBSD: patch-funcs_func__strings.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- funcs/func_strings.c.orig	2018-05-07 17:21:13.413282206 +0000
+++ funcs/func_strings.c
@@ -1483,7 +1483,7 @@ static int string_toupper(struct ast_cha
 {
 	char *bufptr = buf, *dataptr = data;
 
-	while ((bufptr < buf + buflen - 1) && (*bufptr++ = toupper(*dataptr++)));
+	while ((bufptr < buf + buflen - 1) && (*bufptr++ = toupper((unsigned char)*dataptr++)));
 
 	return 0;
 }
@@ -1496,7 +1496,7 @@ static int string_toupper2(struct ast_ch
 		ast_str_make_space(buf, buflen > 0 ? buflen : strlen(data) + 1);
 	}
 	bufptr = ast_str_buffer(*buf);
-	while ((bufptr < ast_str_buffer(*buf) + ast_str_size(*buf) - 1) && (*bufptr++ = toupper(*dataptr++)));
+	while ((bufptr < ast_str_buffer(*buf) + ast_str_size(*buf) - 1) && (*bufptr++ = toupper((unsigned char)*dataptr++)));
 	ast_str_update(*buf);
 
 	return 0;
@@ -1512,7 +1512,7 @@ static int string_tolower(struct ast_cha
 {
 	char *bufptr = buf, *dataptr = data;
 
-	while ((bufptr < buf + buflen - 1) && (*bufptr++ = tolower(*dataptr++)));
+	while ((bufptr < buf + buflen - 1) && (*bufptr++ = tolower((unsigned char)*dataptr++)));
 
 	return 0;
 }
@@ -1525,7 +1525,7 @@ static int string_tolower2(struct ast_ch
 		ast_str_make_space(buf, buflen > 0 ? buflen : strlen(data) + 1);
 	}
 	bufptr = ast_str_buffer(*buf);
-	while ((bufptr < ast_str_buffer(*buf) + ast_str_size(*buf) - 1) && (*bufptr++ = tolower(*dataptr++)));
+	while ((bufptr < ast_str_buffer(*buf) + ast_str_size(*buf) - 1) && (*bufptr++ = tolower((unsigned char)*dataptr++)));
 	ast_str_update(*buf);
 
 	return 0;
