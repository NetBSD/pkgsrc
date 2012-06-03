$NetBSD: patch-src_hwprintf.c,v 1.1 2012/06/03 17:24:08 abs Exp $

At least on NetBSD strlen(h->addch.buf) can hit the -1 case

--- src/hwprintf.c.orig	2008-09-14 21:06:04.000000000 +0000
+++ src/hwprintf.c
@@ -39,7 +39,8 @@ static void h_zero(h_t *h, win_t *win) {
 			max = sizeof(h->addch.buf)-1;
 		memset(h->addch.buf, 0, sizeof(h->addch.buf));
 		nw_getline(h->win, h->addch.buf, sizeof(h->addch.buf));
-		assert(strlen(h->addch.buf) == h->addch.len);
+		assert(strlen(h->addch.buf) == h->addch.len
+		    || strlen(h->addch.buf) == h->addch.len - 1);
 		h->addch.lastwhite = -1;
 		h->addch.firstwhite = -1;
 		h->addch.secondwhite = -1;
