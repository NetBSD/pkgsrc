$NetBSD: patch-panel-plugin_network.cc,v 1.2 2023/05/01 12:05:24 martin Exp $

Fix type error, upstream bug report
https://gitlab.xfce.org/panel-plugins/xfce4-systemload-plugin/-/issues/25
(fixed slightly different but equivalent there)

--- ./panel-plugin/network.cc.orig	2022-02-16 19:57:05.000000000 +0100
+++ ./panel-plugin/network.cc	2023-05-01 00:01:34.366940861 +0200
@@ -116,15 +116,17 @@ read_netload (gulong *net, gulong *NTota
 {
     static guint64 bytes[2];
     static gint64 time[2];
+    gulong val;
 
     *net = 0;
     *NTotal = 0;
 
     time[1] = g_get_monotonic_time ();
 
-    if (read_netload_proc (&bytes[1]) != 0)
-        if (read_netload_libgtop (&bytes[1]) != 0)
+    if (read_netload_proc (&val) != 0)
+        if (read_netload_libgtop (&val) != 0)
             return -1;
+    bytes[1] = val;
 
     if (time[0] != 0 && G_LIKELY (time[1] > time[0]) && G_LIKELY (bytes[1] >= bytes[0]))
     {
