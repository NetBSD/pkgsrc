$NetBSD: patch-vala_sayaka.vala,v 1.1 2016/02/27 14:30:58 tsutsui Exp $

- use colormap files installed into pkgsrc dir

--- vala/sayaka.vala.orig	2016-02-24 12:58:04.000000000 +0000
+++ vala/sayaka.vala
@@ -176,7 +176,7 @@ public class SayakaMain
 		cachedir    = basedir + "cache";
 		tokenfile   = basedir + "token.json";
 		ngwordfile  = basedir + "ngword.json";
-		colormapdir = basedir;
+		colormapdir = "@PREFIX@/share/sayaka";
 
 		address_family = SocketFamily.INVALID;	// UNSPEC がないので代用
 		color_mode = 256;
