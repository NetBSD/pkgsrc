$NetBSD: patch-skkdic-expr.c,v 1.1 2013/03/28 21:28:12 joerg Exp $

--- skkdic-expr.c.orig	2013-03-27 12:46:31.000000000 +0000
+++ skkdic-expr.c
@@ -328,9 +328,7 @@ static void append_item(base, s, e)
 /* 各送りがなエントリは、"わりこmみ"のようなキーを持ち、
  * その値は、"/割り込/割込/"となる
  */
-static char *add_okuri_item(key, s)
-     datum 		*key;
-     unsigned char 	*s;
+static void add_okuri_item(datum *key, unsigned char *s)
 {
     unsigned char	*p, *headtop;
     unsigned char	keybuf[BLEN];
@@ -547,9 +545,7 @@ delete_item(base, s, e)
 /* 各送りがなエントリは、"わりこmみ"のようなキーを持つことになる
  * その値は、"/割り込/割込/"となる
  */
-static char *subtract_okuri_item(key, s)
-     datum 		*key;
-     unsigned char 	*s;
+static void subtract_okuri_item(datum *key, unsigned char *s)
 {
     unsigned char	*p, *headtop;
     unsigned char	keybuf[BLEN];
@@ -597,8 +593,7 @@ static char *subtract_okuri_item(key, s)
 
 /* tailで指している文字列からlineに含まれる語尾を削除
  */
-static int subtract_okuri_tail_line(tails, line)
-     unsigned char 	*tails, *line;
+static void subtract_okuri_tail_line(unsigned char *tails, unsigned char *line)
 {
     unsigned char     	*s, *e;
 
@@ -700,9 +695,7 @@ static void subtract_file(srcname)
     fclose(fp);
 }
 
-static int	okuri_type_out(key, output)
-     datum	*key;
-     FILE	*output;
+static void	okuri_type_out(datum *key, FILE *output)
 {
     unsigned char	*s, *e, *headtop;
     unsigned char	keybuf[BLEN];
