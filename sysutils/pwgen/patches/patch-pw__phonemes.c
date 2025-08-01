$NetBSD: patch-pw__phonemes.c,v 1.1 2025/08/01 08:13:08 jperkin Exp $

https://github.com/tytso/pwgen/commit/54d6c1c0e8c380583c7b3f87c0ff19146232a771

--- pw_phonemes.c.orig	2025-08-01 08:07:04.309469933 +0000
+++ pw_phonemes.c
@@ -111,7 +111,7 @@ try_again:
 			buf[c+len] = '\0'; /* To make strpbrk() happy */
 			cp = strpbrk(buf, pw_ambiguous);
 			if (cp)
-				continue;
+				goto try_again;
 		}
 		
 		c += len;
