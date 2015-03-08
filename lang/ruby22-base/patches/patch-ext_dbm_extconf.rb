$NetBSD: patch-ext_dbm_extconf.rb,v 1.1 2015/03/08 16:24:55 taca Exp $

Fix for Mac OS X 10.4 Tiger.

--- ext/dbm/extconf.rb.orig	2014-10-04 23:33:01.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -136,7 +136,7 @@ def headers.db_check2(db, hdr)
     have_library("gdbm") or return false
   end
 
-  if !have_type("DBM", hdr, hsearch)
+  if !have_type("DBM", ["db.h", hdr], hsearch)
     return false
   end
 
