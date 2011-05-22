$NetBSD: patch-src_brz.c,v 1.1 2011/05/22 11:33:32 alnsn Exp $
https://sourceforge.net/tracker/?func=detail&aid=3303005&group_id=126608&atid=706186

--- src/brz.c.orig	2011-05-15 15:31:05.000000000 +0000
+++ src/brz.c
@@ -981,5 +981,6 @@ cmph_uint32 brz_search_packed(void *pack
 			return brz_bmz8_search_packed(ptr, key, keylen, fingerprint);
 		default: assert(0);
 	}
+	return 0;
 }
 
