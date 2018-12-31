$NetBSD: patch-app_channel.h,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/channel.h.orig	2004-02-09 20:25:11.000000000 +0000
+++ app/channel.h
@@ -39,7 +39,7 @@
 #define GIMP_CHANNEL_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, gimp_channel_get_type(), GimpChannelClass)
 #define GIMP_IS_CHANNEL(obj)     GTK_CHECK_TYPE (obj, gimp_channel_get_type())
 
-guint gimp_channel_get_type (void);
+GtkType gimp_channel_get_type (void);
 
 /*  Special undo type  */
 typedef struct ChannelUndo ChannelUndo;
