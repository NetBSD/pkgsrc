$NetBSD: patch-lib_vpwtable_gdbm__getbyname.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Patch from FreeBSD ports.

--- lib/vpwtable/gdbm_getbyname.cc.orig	2024-02-20 03:21:36.626537464 +0000
+++ lib/vpwtable/gdbm_getbyname.cc
@@ -24,7 +24,7 @@ vpwentry* vpwtable::getbyname(const myst
   if(!db)
     return 0;
   mystring lower = name.lower();
-  datum key = { (char*)lower.c_str(), lower.length() };
+  datum key = { (char*)lower.c_str(), static_cast<int>(lower.length()) };
   datum result = gdbm_fetch(db, key);
   gdbm_close(db);
   return vpwentry::new_from_record(name, mystring(result.dptr, result.dsize));
