$NetBSD: patch-src_Main.cxx,v 1.1 2015/11/06 09:39:14 wiz Exp $

Fix build using patch from
http://bugs.musicpd.org/view.php?id=4452

--- src/Main.cxx.orig	2015-10-16 16:07:10.000000000 +0000
+++ src/Main.cxx
@@ -630,7 +630,7 @@ static int mpd_main_after_fork(struct op
 					 config_get_unsigned(CONF_AUTO_UPDATE_DEPTH,
 							     INT_MAX));
 #else
-		FormatWarning(main_domain,
+		FormatWarning(config_domain,
 			      "inotify: auto_update was disabled. enable during compilation phase");
 #endif
 	}
