$NetBSD: patch-rfbproto.c,v 1.1 2026/03/22 09:41:31 nia Exp $

Fix implicit declaration of isspace(3), isalpha(3).

--- rfbproto.c.orig	2026-03-22 09:24:15.370286540 +0000
+++ rfbproto.c
@@ -26,6 +26,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <ctype.h>
 #include <pwd.h>
 #include <x2vnc.h>
 #include <X11/Xatom.h>
