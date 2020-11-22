$NetBSD: patch-pam_gkr-pam-module.c,v 1.1 2020/11/22 21:26:51 nia Exp $

Argument to ctype functions must be unsigned char.

--- pam/gkr-pam-module.c.orig	2020-02-15 09:30:19.000000000 +0000
+++ pam/gkr-pam-module.c
@@ -137,7 +137,7 @@ static char* 
 strbtrim (char* data)
 {
 	assert (data);
-	while (*data && isspace (*data))
+	while (*data && isspace ((unsigned char)*data))
 		++data;
 	return (char*)data;
 }
