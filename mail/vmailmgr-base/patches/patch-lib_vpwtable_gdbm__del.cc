$NetBSD: patch-lib_vpwtable_gdbm__del.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Patch from FreeBSD ports.

--- lib/vpwtable/gdbm_del.cc.orig	2024-02-20 03:20:54.978827529 +0000
+++ lib/vpwtable/gdbm_del.cc
@@ -23,7 +23,7 @@ bool vpwtable::del(const mystring& name)
   GDBM_FILE db = gdbm_open((char*)filename.c_str(), 0, GDBM_WRITER, 0, 0);
   if(!db)
     return false;
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   bool result = gdbm_delete(db, key) == 0;
   gdbm_close(db);
   return result;
