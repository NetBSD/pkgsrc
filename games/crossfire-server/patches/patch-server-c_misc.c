$NetBSD: patch-server-c_misc.c,v 1.1 2011/08/20 15:32:48 joerg Exp $

Consistently return a value.

--- server/c_misc.c.orig	2011-08-20 14:13:17.000000000 +0000
+++ server/c_misc.c
@@ -1079,7 +1079,7 @@ int command_listen (object *op, char *pa
     if (i < 0) {
         draw_ext_info_format(NDI_UNIQUE, 0, op, MSG_TYPE_COMMAND, MSG_SUBTYPE_NONE,
             "Verbose level should be positive.", NULL);
-        return;
+        return 1;
     }
     op->contr->listening=(char) i;
     draw_ext_info_format(NDI_UNIQUE, 0, op, MSG_TYPE_COMMAND, MSG_SUBTYPE_NONE,
