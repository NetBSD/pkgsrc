$NetBSD: patch-src_mongoc_mongoc-cursor.c,v 1.2 2018/01/02 10:47:52 fhajny Exp $

MAX/MIN overlap with NetBSD sys/param.h's macros, so make sure to get the
local version defined last.

--- src/mongoc/mongoc-cursor.c.orig	2017-12-20 20:37:31.000000000 +0000
+++ src/mongoc/mongoc-cursor.c
@@ -16,7 +16,6 @@
 
 
 #include "mongoc-cursor.h"
-#include "mongoc-cursor-private.h"
 #include "mongoc-client-private.h"
 #include "mongoc-counters-private.h"
 #include "mongoc-error.h"
@@ -27,6 +26,7 @@
 #include "mongoc-util-private.h"
 #include "mongoc-write-concern-private.h"
 #include "mongoc-read-prefs-private.h"
+#include "mongoc-cursor-private.h"
 
 
 #undef MONGOC_LOG_DOMAIN
