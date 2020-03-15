$NetBSD: patch-ext_dbm_extconf.rb,v 1.1 2020/03/15 15:26:22 taca Exp $

Fix for Mac OS X 10.4 Tiger.

--- ext/dbm/extconf.rb.orig	2015-12-16 05:31:54.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -137,7 +137,7 @@ def headers.db_check2(db, hdr)
     have_library("gdbm") or return false
   end
 
-  if !have_type("DBM", hdr, hsearch)
+  if !have_type("DBM", ["db.h", hdr], hsearch)
     return false
   end
 
