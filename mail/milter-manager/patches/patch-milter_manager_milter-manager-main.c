$NetBSD: patch-milter_manager_milter-manager-main.c,v 1.1 2011/05/12 11:28:11 obache Exp $

[manager][process-launcher] fix a bug that process launcher isn't quitted.
https://github.com/milter-manager/milter-manager/commit/6803264e130cb562f972d57ae9d2fcd6e51310fd

--- milter/manager/milter-manager-main.c.orig	2011-04-03 01:56:52.000000000 +0000
+++ milter/manager/milter-manager-main.c
@@ -315,6 +315,16 @@ prepare_process_launcher_pipes_for_manag
     *read_channel = create_read_io_channel(reply_pipe[MILTER_UTILS_READ_PIPE]);
 }
 
+static void
+cb_launcher_finished (MilterFinishedEmittable *emittable,
+                      gpointer user_data)
+{
+    MilterManagerProcessLauncher *launcher;
+
+    launcher = MILTER_MANAGER_PROCESS_LAUNCHER(emittable);
+    milter_manager_process_launcher_shutdown(launcher);
+}
+
 static gboolean
 start_process_launcher (GIOChannel *read_channel, GIOChannel *write_channel,
                         gboolean daemon)
@@ -360,8 +370,11 @@ start_process_launcher (GIOChannel *read
         success = FALSE;
     }
 
-    if (success)
+    if (success) {
+        g_signal_connect(launcher, "finished",
+                         G_CALLBACK(cb_launcher_finished), NULL);
         milter_manager_process_launcher_run(launcher);
+    }
 
     g_object_unref(launcher);
 
