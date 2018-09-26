$NetBSD: patch-ircaux.c,v 1.1 2018/09/26 10:38:26 mrg Exp $

avoid trailing garbage in some variable assignments.

Index: source/ircaux.c
===================================================================
RCS file: /home/cvs/ircii/source/ircaux.c,v
retrieving revision 1.123
retrieving revision 1.124
diff -p -u -r1.123 -r1.124
--- source/ircaux.c	4 Jul 2017 12:10:22 -0000	1.123
+++ source/ircaux.c	13 Sep 2017 21:24:56 -0000	1.124
@@ -946,7 +946,7 @@ double_quote_work(u_char *str, u_char *s
 	}
 	if (dst && pos < dstlen)
 		dst[pos] = '\0';
-	return pos;
+	return pos + 1;
 }
 
 /*
@@ -961,10 +961,10 @@ double_quote(u_char *str, u_char *stuff)
 	size_t len, len2;
 
 	len = double_quote_work(str, stuff, NULL, 0);
-	if (len == 0)
+	if (len == 1)
 		return empty_string();
 
-	dst = new_malloc(len + 1);
+	dst = new_malloc(len);
 	len2 = double_quote_work(str, stuff, dst, len);
 	if (len != len2)
 		yell("--- double_quote() error: len %zu len2 %zu", len, len2);
