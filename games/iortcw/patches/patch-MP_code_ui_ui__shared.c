$NetBSD: patch-MP_code_ui_ui__shared.c,v 1.1 2025/09/26 15:42:16 nia Exp $

Fix incorrect ctype usage. This causes a segfault on startup on
netbsd-11.

--- MP/code/ui/ui_shared.c.orig	2025-09-26 15:37:45.616458946 +0000
+++ MP/code/ui/ui_shared.c
@@ -224,7 +224,7 @@ static unsigned hashForString(const char
 	hash = 0;
 	i = 0;
 	while ( str[i] != '\0' ) {
-		letter = tolower( str[i] );
+		letter = tolower( (unsigned char)str[i] );
 		hash += (unsigned)( letter ) * ( i + 119 );
 		i++;
 	}
