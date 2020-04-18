$NetBSD: patch-ntext.cc,v 1.1 2020/04/18 22:03:58 joerg Exp $

Don't modify const memory in place.

--- ntext.cc.orig	2020-04-17 11:40:43.382486571 +0000
+++ ntext.cc
@@ -237,7 +237,7 @@ void NText::setBG(int c) {
 void NText::append(const char *text, int len, int color) {
   int i;
   NLine *nl;
-  char *p;
+  const char *p;
 
   if (len < 0) {
     discardExcess();
@@ -246,13 +246,10 @@ void NText::append(const char *text, int
 
   p = strchr(text, '\n');
   if (p!=NULL) {
-    *p = 0;
-    i = strlen(text);
-    nl = new NLine(text, color);
-    *p = '\n';
+    nl = new NLine(text, color, p-text);
     lines.push_back(nl);
     formatLine(lines.size()-1);
-    append(&p[1], len-(i+1), color);
+    append(&p[1], len-(p-text+1), color);
     return;
   }
 
