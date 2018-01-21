$NetBSD: patch-src_xitk_session__common.c,v 1.1 2018/01/21 18:44:59 wiz Exp $

Fix buffer overflow

--- src/xitk/session_common.c.orig	2014-02-25 16:52:58.000000000 +0000
+++ src/xitk/session_common.c
@@ -61,7 +61,7 @@ int connect_to_session(int session) {
     euid             = geteuid();
     setuid(euid);
 
-    snprintf(saddr.un.sun_path, 108, "%s%s%d", (xine_get_homedir()), "/.xine/session.", session);
+    snprintf(saddr.un.sun_path, sizeof(saddr.un.sun_path), "%s%s%d", (xine_get_homedir()), "/.xine/session.", session);
     setreuid(stored_uid, euid);
 
     if((connect(fd,&saddr.sa, sizeof(saddr.un))) != -1) {
