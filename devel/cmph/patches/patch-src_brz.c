$NetBSD: patch-src_brz.c,v 1.2 2016/11/20 12:22:48 alnsn Exp $
https://sourceforge.net/tracker/?func=detail&aid=3303005&group_id=126608&atid=706186

--- src/brz.c.orig	2012-06-08 13:39:43.000000000 +0000
+++ src/brz.c
@@ -982,4 +982,5 @@ cmph_uint32 brz_search_packed(void *pack
 			return brz_bmz8_search_packed(ptr, key, keylen, fingerprint);
 		default: assert(0);
 	}
+	return 0;
 }
