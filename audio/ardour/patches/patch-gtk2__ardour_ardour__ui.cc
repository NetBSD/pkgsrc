$NetBSD: patch-gtk2__ardour_ardour__ui.cc,v 1.2 2020/03/04 10:56:35 nia Exp $

Support NetBSD.

https://github.com/Ardour/ardour/pull/469

--- gtk2_ardour/ardour_ui.cc.orig	2017-09-15 20:56:22.000000000 +0000
+++ gtk2_ardour/ardour_ui.cc
@@ -1336,7 +1336,7 @@ ARDOUR_UI::check_memory_locking ()
 						  "You can view the memory limit with 'ulimit -l', "
 						  "and it is normally controlled by %2"),
 						PROGRAM_NAME,
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 						X_("/etc/login.conf")
 #else
 						X_(" /etc/security/limits.conf")
