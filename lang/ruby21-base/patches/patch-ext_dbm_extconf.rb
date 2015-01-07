$NetBSD: patch-ext_dbm_extconf.rb,v 1.1 2015/01/07 10:37:56 taca Exp $

Fix for Mac OS X 10.4 Tiger.

--- ext/dbm/extconf.rb.orig	2013-08-12 03:59:50.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -136,7 +136,7 @@ def headers.db_check2(db, hdr)
     have_library("gdbm") or return false
   end
 
-  if !have_type("DBM", hdr, hsearch)
+  if !have_type("DBM", ["db.h", hdr], hsearch)
     return false
   end
 
