$NetBSD: patch-erts_emulator_nifs_common_prim__net__nif.c,v 1.1 2019/11/18 20:46:02 nia Exp $

Using bool as a variable name isn't a good idea since it conflicts with
the keyword. For now, just undefine the keyword.

--- erts/emulator/nifs/common/prim_net_nif.c.orig	2019-11-08 11:19:37.000000000 +0000
+++ erts/emulator/nifs/common/prim_net_nif.c
@@ -209,6 +209,8 @@
 #  define SOCKLEN_T size_t
 #endif
 
+#undef bool
+
 /* Debug stuff... */
 #define NET_NIF_DEBUG_DEFAULT FALSE
 
