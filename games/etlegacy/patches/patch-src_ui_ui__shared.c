$NetBSD: patch-src_ui_ui__shared.c,v 1.1 2025/09/28 10:12:27 nia Exp $

Fix ctype usage to avoid segfault on startup with netbsd-11.

--- src/ui/ui_shared.c.orig	2025-09-28 09:30:35.307160979 +0000
+++ src/ui/ui_shared.c
@@ -176,7 +176,7 @@ static long hashForString(const char *st
 
 	while (str[i] != '\0')
 	{
-		letter = (char)tolower(str[i]);
+		letter = (char)tolower((unsigned char)str[i]);
 		hash  += (long)(letter) * (i + 119);
 		i++;
 	}
