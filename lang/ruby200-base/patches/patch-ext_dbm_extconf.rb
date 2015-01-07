$NetBSD: patch-ext_dbm_extconf.rb,v 1.1 2015/01/07 10:37:11 taca Exp $

Fix for Mac OS X 10.4 Tiger.

--- ext/dbm/extconf.rb.orig	2012-09-04 00:57:31.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -119,7 +119,7 @@ def headers.db_check2(db, hdr)
     have_library("gdbm") or return false
   end
 
-  if !have_type("DBM", hdr, hsearch)
+  if !have_type("DBM", ["db.h", hdr], hsearch)
     return false
   end
 
