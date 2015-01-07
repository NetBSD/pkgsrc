$NetBSD: patch-ext_dbm_extconf.rb,v 1.4 2015/01/07 10:35:59 taca Exp $

Fix for Mac OS X 10.4 Tiger.

--- ext/dbm/extconf.rb.orig    2014-12-28 14:04:40.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -247,7 +247,7 @@ def headers.db_check2(db, hdr)
     have_library("gdbm") or return false
   end
 
-  if have_type("DBM", hdr, hsearch) and
+  if have_type("DBM", ["db.h", hdr], hsearch) and
      (db == 'libc' ? have_func('dbm_open("", 0, 0)', hdr, hsearch) :
                      have_library(db, 'dbm_open("", 0, 0)', hdr, hsearch)) and
      have_func('dbm_clearerr((DBM *)0)', hdr, hsearch) and
