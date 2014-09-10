$NetBSD: patch-src_notify.hxx,v 1.2 2014/09/10 12:16:55 wiz Exp $

http://bugs.musicpd.org/view.php?id=4110

--- src/notify.hxx.orig	2014-09-09 20:11:34.000000000 +0000
+++ src/notify.hxx
@@ -28,9 +28,6 @@ struct notify {
 	Cond cond;
 	bool pending;
 
-#ifndef WIN32
-	constexpr
-#endif
 	notify():pending(false) {}
 
 	/**
