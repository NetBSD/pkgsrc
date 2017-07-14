$NetBSD: patch-gnome-dictionary_libgdict_gdict-client-context.h,v 1.1 2017/07/14 12:57:23 joerg Exp $

--- gnome-dictionary/libgdict/gdict-client-context.h.orig	2017-07-12 23:39:46.323552444 +0000
+++ gnome-dictionary/libgdict/gdict-client-context.h
@@ -21,6 +21,7 @@
 #define __GDICT_CLIENT_CONTEXT_H__
 
 #include <glib-object.h>
+#include "gdict-context.h"
 
 #define GDICT_TYPE_CLIENT_CONTEXT		(gdict_client_context_get_type ())
 #define GDICT_CLIENT_CONTEXT(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GDICT_TYPE_CLIENT_CONTEXT, GdictClientContext))
