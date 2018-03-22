$NetBSD: patch-src_grip.h,v 1.3 2018/03/22 13:29:11 triaxx Exp $

--- src/grip.h.orig	2018-01-01 20:16:03.000000000 +0000
+++ src/grip.h
@@ -59,6 +59,12 @@
 
 #endif
 
+#if defined(__NetBSD__)
+#define CD_DEVICE "/dev/rcd0d"
+#else
+#define CD_DEVICE "/dev/cdrom"
+#endif
+
 typedef struct _grip_gui {
   GtkWidget *app;
   GtkWidget *winbox;
