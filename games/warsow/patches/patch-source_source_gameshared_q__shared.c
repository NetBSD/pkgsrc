$NetBSD: patch-source_source_gameshared_q__shared.c,v 1.1 2025/09/29 13:31:29 nia Exp $

- Avoid a segfault on startup on netbsd-11 via incorrect ctype usage.

--- source/source/gameshared/q_shared.c.orig	2025-09-29 09:27:41.708406069 +0000
+++ source/source/gameshared/q_shared.c
@@ -1152,7 +1152,7 @@ char *Q_strlwr( char *s )
 	if( s )
 	{
 		for( p = s; *s; s++ )
-			*s = tolower( *s );
+			*s = tolower( (unsigned char)*s );
 		return p;
 	}
 
