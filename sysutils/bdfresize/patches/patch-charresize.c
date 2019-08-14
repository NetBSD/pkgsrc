$NetBSD: patch-charresize.c,v 1.1 2019/08/14 17:21:06 fcambus Exp $

Fix conflicting types for 'malloc' error.

--- charresize.c.orig	2019-01-01 14:29:28.177478590 +0000
+++ charresize.c
@@ -46,7 +46,6 @@ static int	bit[8] = { 0x80, 0x40, 0x20, 
 void
 processChar(void)
 {
-  char	*malloc();
   char	*srcimage;
   int	*dstgray;
 
