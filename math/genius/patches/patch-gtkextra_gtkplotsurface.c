$NetBSD: patch-gtkextra_gtkplotsurface.c,v 1.1 2013/03/02 18:02:11 joerg Exp $

--- gtkextra/gtkplotsurface.c.orig	2013-03-01 16:05:52.000000000 +0000
+++ gtkextra/gtkplotsurface.c
@@ -99,7 +99,7 @@ enum {
 static GtkPlotDataClass *parent_class = NULL;
 
 /* "stolen" from 3dgpl */
-inline gulong _sqrt(register gulong arg)
+static inline gulong _sqrt(register gulong arg)
 { 
    register gint i;
    register gulong nprd,msk=0x8000L,val=0,prd=0;
