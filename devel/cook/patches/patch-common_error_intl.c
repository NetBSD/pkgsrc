$NetBSD: patch-common_error_intl.c,v 1.1 2025/09/29 20:46:56 mrg Exp $

--- common/error_intl.c.orig	2006-01-16 17:56:01.000000000 -0800
+++ common/error_intl.c	2025-09-25 10:17:35.313135499 -0700
@@ -153,7 +153,7 @@
 		kanji = wctype("kanji");
 		kanji_set = 1;
 	}
-	if (kanji && iswctype(kanji, wc))
+	if (kanji && iswctype(wc, kanji))
 		return 2;
 #endif
 	return 1;
