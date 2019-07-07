$NetBSD: patch-src_input.c,v 1.1 2019/07/07 13:32:18 nia Exp $

Don't free unallocated memory.

(Apparently G_OS_UNIX is actually G_OS_LINUX).

--- src/input.c.orig	2018-05-01 16:59:49.000000000 +0000
+++ src/input.c
@@ -53,12 +53,12 @@ void close_channels(guidata *gui)
   int a;
   for (a=0;a<9;a++)
   {
+#ifdef G_OS_UNIX
     if (gui->joy[a].id != NULL)
     {
       g_free(gui->joy[a].id);
     }
 
-#ifdef G_OS_UNIX
     if (gui->joy[a].channel != NULL)
     {
       g_io_channel_unref(gui->joy[a].channel);
