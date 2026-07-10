$NetBSD: patch-Wnn_jserver_daibn__kai.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove an unnecessary old stype function declaration

--- Wnn/jserver/daibn_kai.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/daibn_kai.c
@@ -310,7 +310,6 @@ zentan_able (v, hinsi, fzkchar)
   w_char *fzk_buf;
   int fzkcnt;
   int fzklen;
-  w_char *rev_fzk ();
 #endif /* NO_FZK */
 
   if (hinsi == WNN_ALL_HINSI)
