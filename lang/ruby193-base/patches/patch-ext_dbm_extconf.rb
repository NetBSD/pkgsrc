$NetBSD: patch-ext_dbm_extconf.rb,v 1.1 2012/02/18 05:03:34 taca Exp $

Fix build problem on NetBSD (and might be other *BSD).

--- ext/dbm/extconf.rb.orig	2012-02-16 08:56:21.000000000 +0000
+++ ext/dbm/extconf.rb
@@ -5,8 +5,7 @@ dir_config("dbm")
 if dblib = with_config("dbm-type", nil)
   dblib = dblib.split(/[ ,]+/)
 else
-  #dblib = %w(libc db db2 db1 db5 db4 db3 dbm gdbm gdbm_compat qdbm)
-  dblib = %w(gdbm gdbm_compat qdbm)
+  dblib = %w(libc db db2 db1 db5 db4 db3 dbm gdbm gdbm_compat qdbm)
 end
 
 headers = {
