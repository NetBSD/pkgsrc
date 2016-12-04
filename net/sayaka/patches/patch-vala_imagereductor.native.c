$NetBSD: patch-vala_imagereductor.native.c,v 1.1 2016/12/04 04:22:24 tsutsui Exp $

- pull upstream fix for crash caused by out of bounce access
 https://github.com/isaki68k/sayaka/commit/80f7e7b2e766c142b75378c32d8a733780131c43

--- vala/imagereductor.native.c.orig	2016-11-25 06:08:13.000000000 +0000
+++ vala/imagereductor.native.c
@@ -881,7 +881,8 @@ ImageReductor_HighQuality(
 			errbuf[i] = errbuf[i + 1];
 		}
 		errbuf[errbuf_count - 1] = tmp;
-		memset(errbuf[errbuf_count - 1], 0, errbuf_len);
+		// errbuf[y] には左マージンがあるのを考慮する
+		memset(errbuf[errbuf_count - 1] - errbuf_left, 0, errbuf_len);
 	}
 
 	free(errbuf_mem);
