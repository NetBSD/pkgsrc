$NetBSD: patch-romkan-org.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- romkan-org.c.orig	2012-12-20 14:39:27.000000000 +0000
+++ romkan-org.c
@@ -187,6 +187,9 @@ char *modeString[] = {
 	"単語選択",
 };
 
+void inputKanaConso(char c, void (*output)(),void (*flush)());
+void flushLastConso(char *c, void (*output)(), void (*flush)());
+
 void writeShells(),flushOut();
 
 void
@@ -261,10 +264,7 @@ void (*output)();
 	Nconso = 0;
 }
 
-inputKanaConso(c,output,flush)
-char c;
-void (*output)();
-void (*flush)();
+void inputKanaConso(char c, void (*output)(),void (*flush)())
 {
 	char notOverwrite = 0;
 	switch (c) {
@@ -356,9 +356,7 @@ void (*flush)();
 	write1(c);
 }
 
-flushLastConso(c,output,flush)
-char c;
-void (*output)(),(*flush)();
+void flushLastConso(char *c, void (*output)(), void (*flush)())
 {
         if (Nconso == 0) {
 		return;
