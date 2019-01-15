$NetBSD: patch-src_db_VHelper.cxx,v 1.1 2019/01/15 10:04:53 wiz Exp $

../src/db/VHelper.cxx:61:17: error: use of undeclared identifier 'strtol'
https://github.com/MusicPlayerDaemon/MPD/issues/456

--- src/db/VHelper.cxx.orig	2019-01-04 18:22:21.000000000 +0000
+++ src/db/VHelper.cxx
@@ -23,6 +23,7 @@
 #include "song/Filter.hxx"
 
 #include <assert.h>
+#include <stdlib.h>
 #include <string.h>
 
 DatabaseVisitorHelper::DatabaseVisitorHelper(const DatabaseSelection &_selection,
