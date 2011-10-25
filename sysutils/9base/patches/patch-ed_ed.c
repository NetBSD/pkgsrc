$NetBSD: patch-ed_ed.c,v 1.1 2011/10/25 16:28:17 ryoon Exp $

* Support DragonFly

--- ed/ed.c.orig	2010-06-04 10:46:05.000000000 +0000
+++ ed/ed.c
@@ -121,7 +121,7 @@ void	setnoaddr(void);
 void	setwide(void);
 void	squeeze(int);
 void	substitute(int);
-char*	_mktemp(char *as);
+char*	my_mktemp(char *as);
 
 Rune La[] = { 'a', 0 };
 Rune Lr[] = { 'r', 0 };
@@ -162,7 +162,7 @@ main(int argc, char *argv[])
 		globp = Lr;
 	}
 	zero = malloc((nlall+5)*sizeof(int*));
-	tfname = _mktemp(tmp);
+	tfname = my_mktemp(tmp);
 	init();
 	setjmp(savej);
 	commands();
@@ -1584,7 +1584,7 @@ putchr(int ac)
 }
 
 char*
-_mktemp(char *as)
+my_mktemp(char *as)
 {
 	char *s;
 	unsigned pid;
