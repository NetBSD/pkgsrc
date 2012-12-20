$NetBSD: patch-spider.c,v 1.1 2012/12/20 22:05:06 joerg Exp $

--- spider.c.orig	2012-12-20 18:05:35.000000000 +0000
+++ spider.c
@@ -218,8 +218,7 @@ int	num;
 /*
  * deal hand of 10
  */
-deal_next_hand(log)
-Bool	log;
+void deal_next_hand(Bool log)
 {
 int	i;
 CardPtr	tmp;
@@ -936,8 +935,7 @@ char	buf[128];
 /*
  * print cards in list
  */
-expand(list)
-CardList	list;
+void expand(CardList list)
 {
 CardPtr	tmp, last;
 char	buf[512], buf2[10];
