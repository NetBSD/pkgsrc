$NetBSD: patch-src_notify.hxx,v 1.1 2014/09/10 12:10:23 joerg Exp $

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
