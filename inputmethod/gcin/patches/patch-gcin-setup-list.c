$NetBSD: patch-gcin-setup-list.c,v 1.1 2013/02/26 11:09:46 joerg Exp $

--- gcin-setup-list.c.orig	2013-02-25 17:59:05.000000000 +0000
+++ gcin-setup-list.c
@@ -184,7 +184,7 @@ static gboolean toggled (GtkCellRenderer
   int in_no = gcin_switch_keys_lookup(key[0]);
 
   if (in_no < 0)
-    return;
+    return FALSE;
 
   gcin_flags_im_enabled ^= 1 << in_no;
   value ^= 1;
