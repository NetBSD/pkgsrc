$NetBSD: patch-libempathy_empathy-auth-factory.c,v 1.1 2013/05/04 22:38:14 prlw1 Exp $

Needed for use with telepathy-glib-0.20.2

--- libempathy/empathy-auth-factory.c.orig	2011-03-24 15:15:16.000000000 +0000
+++ libempathy/empathy-auth-factory.c
@@ -20,6 +20,7 @@
 
 #include "empathy-auth-factory.h"
 
+#include <telepathy-glib/channel-dispatch-operation.h>
 #include <telepathy-glib/interfaces.h>
 #include <telepathy-glib/simple-handler.h>
 #include <telepathy-glib/util.h>
