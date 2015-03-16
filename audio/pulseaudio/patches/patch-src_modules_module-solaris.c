$NetBSD: patch-src_modules_module-solaris.c,v 1.1 2015/03/16 14:57:49 jperkin Exp $

Catch up with newer API.

--- src/modules/module-solaris.c.orig	2015-02-12 14:10:35.000000000 +0000
+++ src/modules/module-solaris.c
@@ -412,10 +412,12 @@ static int sink_process_msg(pa_msgobject
                         pa_smoother_resume(u->smoother, pa_rtclock_now(), true);
 
                         if (!u->source || u->source_suspended) {
+                            bool mute;
                             if (unsuspend(u) < 0)
                                 return -1;
                             u->sink->get_volume(u->sink);
-                            u->sink->get_mute(u->sink);
+                            if (u->sink->get_mute(u->sink, &mute) >= 0)
+                                pa_sink_set_mute(u->sink, mute, false);
                         }
                         u->sink_suspended = false;
                     }
@@ -1033,8 +1035,12 @@ int pa__init(pa_module *m) {
 
         if (sink_new_data.muted_is_set)
             u->sink->set_mute(u->sink);
-        else
-            u->sink->get_mute(u->sink);
+        else {
+            bool mute;
+
+            if (u->sink->get_mute(u->sink, &mute) >= 0)
+                pa_sink_set_mute(u->sink, mute, false);
+        }
 
         pa_sink_put(u->sink);
     }
