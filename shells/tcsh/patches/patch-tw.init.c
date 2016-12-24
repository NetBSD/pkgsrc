$NetBSD: patch-tw.init.c,v 1.1 2016/12/24 13:18:43 kim Exp $

Don't play pointer tricks that are undefined in modern c (Brooks Davis)

Index: tw.init.c
===================================================================
RCS file: /p/tcsh/cvsroot/tcsh/tw.init.c,v
retrieving revision 3.42
retrieving revision 3.43
diff -u -r3.42 -r3.43
--- tw.init.c	17 Apr 2011 14:49:30 -0000	3.42
+++ tw.init.c	7 Dec 2016 02:52:27 -0000	3.43
@@ -125,9 +125,8 @@
 	sl->buff = xrealloc(sl->buff, sl->tbuff * sizeof(Char));
 	/* Re-thread the new pointer list, if changed */
 	if (ptr != NULL && ptr != sl->buff) {
-	    intptr_t offs = sl->buff - ptr;
 	    for (i = 0; i < sl->nlist; i++)
-		sl->list[i] += offs;
+		sl->list[i] = sl->buff + (sl->list[i] - ptr);
 	}
 	disabled_cleanup(&pintr_disabled);
     }
