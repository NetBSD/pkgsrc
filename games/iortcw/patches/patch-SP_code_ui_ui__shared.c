$NetBSD: patch-SP_code_ui_ui__shared.c,v 1.1 2025/09/26 15:42:16 nia Exp $

Fix incorrect ctype usage. This causes a segfault on startup on
netbsd-11.

--- SP/code/ui/ui_shared.c.orig	2025-09-26 15:36:35.439948084 +0000
+++ SP/code/ui/ui_shared.c
@@ -296,7 +296,7 @@ static unsigned hashForString(const char
 	hash = 0;
 	i = 0;
 	while ( str[i] != '\0' ) {
-		letter = tolower( str[i] );
+		letter = tolower( (unsigned char)str[i] );
 		hash += (unsigned)( letter ) * ( i + 119 );
 		i++;
 	}
