$NetBSD: patch-lib_chainbutton.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- lib/chainbutton.c.orig	2006-11-24 20:50:47.000000000 +0000
+++ lib/chainbutton.c
@@ -155,7 +155,7 @@ gimp_chain_button_init (GimpChainButton 
 GtkType
 gimp_chain_button_get_type (void)
 {
-  static guint gcb_type = 0;
+  static GtkType gcb_type = 0;
 
   if (!gcb_type)
     {
