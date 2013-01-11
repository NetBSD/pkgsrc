$NetBSD: patch-readline_keymaps.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- readline/keymaps.c.orig	2013-01-11 12:47:12.000000000 +0000
+++ readline/keymaps.c
@@ -110,7 +110,7 @@ rl_discard_keymap (map)
   int i;
 
   if (!map)
-    return;
+    return 0;
 
   for (i = 0; i < 128; i++)
     {
@@ -128,6 +128,7 @@ rl_discard_keymap (map)
 	  break;
 	}
     }
+  return 0;
 }
 
 #ifdef STATIC_MALLOC
