$NetBSD: patch-audio__dev.h,v 1.1 2012/02/05 20:39:50 sbd Exp $

--- audio_dev.h.orig	2004-06-07 21:10:42.000000000 +0000
+++ audio_dev.h
@@ -71,4 +71,8 @@ extern const struct audio_dev_backend au
 extern const struct audio_dev_backend audio_dev_arts;
 #endif
 
+#ifndef INFTIM
+#define INFTIM (-1)
+#endif
+
 #endif /* __AUDIO_DEV_H */
