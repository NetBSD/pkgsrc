$NetBSD: patch-kkconv.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- kkconv.c.orig	2012-12-20 14:39:31.000000000 +0000
+++ kkconv.c
@@ -29,6 +29,9 @@ LearnMode NetLearnMode = NET_LEARN_MODE;
 static void putOkuri();
 void showCand();
 
+void inputKanaConso(char c, void (*output)(),void (*flush)());
+void flushLastConso(char *c, void (*output)(), void (*flush)());
+
 static void
 bufferedInput(s)
 char *s;
