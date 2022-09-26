$NetBSD: patch-common_error__intl.c,v 1.1 2022/09/26 10:21:32 nros Exp $

* call iswctype with the right arguments

--- common/error_intl.c.orig	2022-09-26 07:07:12.160390023 +0000
+++ common/error_intl.c
@@ -146,7 +146,7 @@ column_width(wchar_t wc)
 		kanji = wctype("kanji");
 		kanji_set = 1;
 	}
-	if (kanji && iswctype(kanji, wc))
+	if (kanji && iswctype(wc, kanji))
 		return 2;
 #endif
 	return 1;
