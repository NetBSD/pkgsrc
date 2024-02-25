$NetBSD: patch-lib_vpwtable_gdbm__exists.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Patch from FreeBSD ports.

--- lib/vpwtable/gdbm_exists.cc.orig	2024-02-20 03:21:16.821104286 +0000
+++ lib/vpwtable/gdbm_exists.cc
@@ -23,7 +23,7 @@ bool vpwtable::exists(const mystring& na
   GDBM_FILE db = gdbm_open((char*)filename.c_str(), 0, GDBM_READER, 0, 0);
   if(!db)
     return false;
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   bool result = gdbm_exists(db, key);
   gdbm_close(db);
   return result;
