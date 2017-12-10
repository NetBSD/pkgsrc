$NetBSD: patch-autoreload_nop.c,v 1.1 2017/12/10 16:37:53 leot Exp $

Avoid 100% CPU usage when sxiv is called non-interactively.

Reported upstream as issue #297:

 <https://github.com/muennich/sxiv/issues/297>

--- autoreload_nop.c.orig	2017-10-27 15:25:56.000000000 +0000
+++ autoreload_nop.c
@@ -20,7 +20,7 @@
 
 void arl_init(arl_t *arl)
 {
-	(void) arl;
+	arl->fd = -1;
 }
 
 void arl_cleanup(arl_t *arl)
