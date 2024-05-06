$NetBSD: patch-source_src_console.cpp,v 1.1 2024/05/06 12:12:16 nia Exp $

No idea what this is trying to do, but the function doesn't resolve.

--- source/src/console.cpp.orig	2024-05-06 12:04:56.534059613 +0000
+++ source/src/console.cpp
@@ -379,9 +379,6 @@ void pasteconsole(char *dst)
     GlobalUnlock(cb);
     CloseClipboard();
     #elif defined(__APPLE__)
-    extern void mac_pasteconsole(char *commandbuf);
-
-    mac_pasteconsole(dst);
     #else
     SDL_SysWMinfo wminfo;
     SDL_VERSION(&wminfo.version);
