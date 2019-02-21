$NetBSD: patch-xvinfo.c,v 1.1 2019/02/21 14:32:32 tsutsui Exp $

- fix a small string buffer that was truncating some libpng messages

--- xvinfo.c.orig	2019-02-21 14:07:38.372613477 +0000
+++ xvinfo.c
@@ -26,7 +26,7 @@
 #define INFOHIGH 270
 
 /* max length of an Info String */
-#define ISTRLEN 80
+#define ISTRLEN 256
 
 /* baseline of top line of text */
 #define TOPBASE (36 + penn_height/2 + 4 + 8 + ASCENT)
