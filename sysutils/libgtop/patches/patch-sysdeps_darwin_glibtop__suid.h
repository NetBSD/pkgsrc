$NetBSD: patch-sysdeps_darwin_glibtop__suid.h,v 1.1 2016/04/07 11:54:57 youri Exp $

Fix Darwin build.

--- sysdeps/darwin/glibtop_suid.h.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/darwin/glibtop_suid.h
@@ -22,6 +22,8 @@
 
 G_BEGIN_DECLS
 
+#include <glibtop_machine.h>
+
 static inline void glibtop_suid_enter (glibtop *server) {
 	setreuid (server->machine.uid, server->machine.euid);
 };
