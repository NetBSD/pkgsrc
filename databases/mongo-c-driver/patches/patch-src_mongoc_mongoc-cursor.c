$NetBSD: patch-src_mongoc_mongoc-cursor.c,v 1.1 2016/12/17 14:25:31 joerg Exp $

MAX/MIN overlap with NetBSD sys/param.h's macros, so make sure to get the
local version defined last.

--- src/mongoc/mongoc-cursor.c.orig	2016-12-17 13:38:09.957899312 +0000
+++ src/mongoc/mongoc-cursor.c
@@ -16,7 +16,6 @@
 
 
 #include "mongoc-cursor.h"
-#include "mongoc-cursor-private.h"
 #include "mongoc-client-private.h"
 #include "mongoc-counters-private.h"
 #include "mongoc-error.h"
@@ -26,6 +25,7 @@
 #include "mongoc-read-concern-private.h"
 #include "mongoc-util-private.h"
 #include "mongoc-write-concern-private.h"
+#include "mongoc-cursor-private.h"
 
 
 #undef MONGOC_LOG_DOMAIN
