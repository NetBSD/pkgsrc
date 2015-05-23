$NetBSD: patch-src_softmagic.c,v 1.1 2015/05/23 13:11:07 bsiegert Exp $

contains fix from 
https://github.com/file/file/commit/3046c231e1a2fcdd5033bea0603c23f435a00bd7

--- src/softmagic.c.orig	2015-01-01 17:07:34.000000000 +0000
+++ src/softmagic.c
@@ -1116,10 +1116,8 @@ mcopy(struct magic_set *ms, union VALUET
 				bytecnt = m->str_range;
 			}
 
-			if (bytecnt == 0)
-				bytecnt = 8192;
-			if (bytecnt > nbytes)
-				bytecnt = nbytes;
+			if (bytecnt == 0 || bytecnt > nbytes - offset)
+				bytecnt = nbytes - offset;
 
 			buf = RCAST(const char *, s) + offset;
 			end = last = RCAST(const char *, s) + bytecnt;
