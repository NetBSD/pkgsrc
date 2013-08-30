$NetBSD: patch-ext_rnotify.c,v 1.1 2013/08/30 16:55:47 joerg Exp $

--- ext/rnotify.c.orig	2013-08-30 16:12:51.000000000 +0000
+++ ext/rnotify.c
@@ -12,6 +12,10 @@
 #define MODULE_NAME "Notify"
 #define CLASS_NAME "Notification"
 
+#ifndef UNUSED
+#define UNUSED(x) x
+#endif
+
 typedef struct _ActionData ActionData;
 struct _ActionData
 {
