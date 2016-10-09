$NetBSD: patch-vala_sayaka.vala,v 1.2 2016/10/09 17:15:18 tsutsui Exp $

- use colormap files installed into pkgsrc dir
- pull upstream fix:
 https://github.com/isaki68k/sayaka/commit/c2b2974d75cc63cfd51f57253b112257ee912f6e

--- vala/sayaka.vala.orig	2016-09-25 11:53:37.000000000 +0000
+++ vala/sayaka.vala
@@ -170,7 +170,7 @@ public class SayakaMain
 		cachedir    = basedir + "cache";
 		tokenfile   = basedir + "token.json";
 		ngwordfile  = basedir + "ngword.json";
-		colormapdir = basedir;
+		colormapdir = "@PREFIX@/share/sayaka";
 
 		address_family = SocketFamily.INVALID;	// UNSPEC がないので代用
 		color_mode = 256;
@@ -1445,7 +1445,7 @@ public class SayakaMain
 		}
 
 		// メディア情報を展開
-		if (media_entities != null) {
+		if (media_entities != null && media_entities.Has("media")) {
 			var media = media_entities.GetArray("media");
 			for (var i = 0; i < media.length; i++) {
 				var m = media.index(i);
