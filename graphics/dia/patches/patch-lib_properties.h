$NetBSD: patch-lib_properties.h,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/f57ea2685034ddbafc19f35d9b525a12283d7c24
via Fedora

--- lib/properties.h.orig	2014-08-24 15:46:01.000000000 +0000
+++ lib/properties.h
@@ -116,7 +116,7 @@ typedef void (*PropertyType_GetFromOffse
                                          void *base, guint offset, guint offset2);
 typedef void (*PropertyType_SetFromOffset)(Property *prop,
                                          void *base, guint offset, guint offset2);
-typedef int (*PropertyType_GetDataSize)(Property *prop);
+typedef int (*PropertyType_GetDataSize)(void);
 
 
 struct _PropertyOps {
