$NetBSD: patch-src_pause_dialog.cpp,v 1.1 2020/09/30 08:07:57 nia Exp $

[PATCH] Fix use after free. See #161

https://github.com/nxengine/nxengine-evo/commit/f2135e34461eb8bcc74e3a4493840421ed15bca8.patch

--- src/pause/dialog.cpp.orig	2019-04-08 14:37:06.000000000 +0000
+++ src/pause/dialog.cpp
@@ -260,10 +260,10 @@ void Dialog::RunInput()
       }
       else if ((item->type == OD_ACTIVATED) && item->activate && (dir == 0))
       {
-        (*item->activate)(item, dir);
-
         if (item->update)
           (*item->update)(item);
+
+        (*item->activate)(item, dir);
       }
       else if ((item->type == OD_CHOICE) && item->activate && (dir != 0))
       {
