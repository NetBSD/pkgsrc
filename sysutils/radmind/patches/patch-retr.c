$NetBSD: patch-retr.c,v 1.2 2018/12/18 14:16:18 hauke Exp $

Remove stale extern declaration

--- retr.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ retr.c
@@ -47,7 +47,6 @@ extern int		verbose;
 extern int		showprogress;
 extern int		dodots;
 extern int		cksum;
-extern int		errno;
 extern int		create_prefix;
 extern SSL_CTX  	*ctx;
 
