$NetBSD: patch-tty-term.c,v 1.1 2018/10/21 21:22:47 leot Exp $

Address -Wint-conversion warnings and properly cast to long, from
NetBSD external/bsd/tmux/dist/tty-term.c patch by <christos>.

This was applied upstream via:

 <https://github.com/tmux/tmux/pull/1465>

--- tty-term.c.orig	2018-07-27 13:01:14.000000000 +0000
+++ tty-term.c
@@ -616,14 +616,14 @@ tty_term_string3(struct tty_term *term, 
 const char *
 tty_term_ptr1(struct tty_term *term, enum tty_code_code code, const void *a)
 {
-	return (tparm((char *) tty_term_string(term, code), a, 0, 0, 0, 0, 0, 0, 0, 0));
+	return (tparm((char *) tty_term_string(term, code), (long)a, 0, 0, 0, 0, 0, 0, 0, 0));
 }
 
 const char *
 tty_term_ptr2(struct tty_term *term, enum tty_code_code code, const void *a,
     const void *b)
 {
-	return (tparm((char *) tty_term_string(term, code), a, b, 0, 0, 0, 0, 0, 0, 0));
+	return (tparm((char *) tty_term_string(term, code), (long)a, (long)b, 0, 0, 0, 0, 0, 0, 0));
 }
 
 int
