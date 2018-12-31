$NetBSD: patch-lib_size__entry.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- lib/size_entry.c.orig	2006-11-23 23:58:28.000000000 +0000
+++ lib/size_entry.c
@@ -169,7 +169,7 @@ gimp_size_entry_init (GimpSizeEntry *gse
 GtkType
 gimp_size_entry_get_type (void)
 {
-  static guint gse_type = 0;
+  static GtkType gse_type = 0;
 
   if (!gse_type)
     {
