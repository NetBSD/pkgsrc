$NetBSD: patch-bisect.c,v 1.1 2020/01/09 12:12:17 wiz Exp $

%m is only allowed in syslog(3) like functions [-Wformat=]
https://github.com/googleprojectzero/halfempty/pull/11

--- bisect.c.orig	2019-03-16 17:55:00.000000000 +0000
+++ bisect.c
@@ -202,7 +202,7 @@ static task_t * strategy_bisect_data(GNo
                        source->fd,
                        0,
                        childstatus->offset) == false) {
-        g_error("sendfile failed while trying to construct new file, %m");
+        g_error("sendfile failed while trying to construct new file, %s", strerror(errno));
         goto nochildunlock;
     }
 
@@ -215,7 +215,7 @@ static task_t * strategy_bisect_data(GNo
                            source->size
                                 - childstatus->chunksize
                                 - childstatus->offset) == false) {
-            g_error("sendfile failed while trying to construct new file, %m");
+            g_error("sendfile failed while trying to construct new file, %s", strerror(errno));
             goto nochildunlock;
         }
 
