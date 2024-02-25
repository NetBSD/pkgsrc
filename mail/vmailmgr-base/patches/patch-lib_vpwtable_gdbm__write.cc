$NetBSD: patch-lib_vpwtable_gdbm__write.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Patch from FreeBSD ports.

--- lib/vpwtable/gdbm_write.cc.orig	2015-09-01 16:03:21.000000000 +0000
+++ lib/vpwtable/gdbm_write.cc
@@ -16,14 +16,15 @@
 
 #include <config.h>
 #include <errno.h>
+#include <unistd.h>
 #include "vpwtable.h"
 #include <gdbm.h>
 
 class gdbm_vpwtable_writer : public vpwtable_writer
 {
 private:
-  const mystring& tmpname;
-  const mystring& destname;
+  const mystring tmpname;
+  const mystring destname;
   GDBM_FILE out;
   bool opened;
 public:
@@ -59,10 +60,10 @@ bool gdbm_vpwtable_writer::operator!() c
 
 bool gdbm_vpwtable_writer::put(const vpwentry& vpw)
 {
-  mystring name = vpw->name.lower();
-  datum key = { (char*)name.c_str(), name.length() };
-  mystring binary = vpw->to_record();
-  datum data = { (char*)binary.c_str(), binary.length() };
+  mystring name = vpw.name.lower();
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
+  mystring binary = vpw.to_record();
+  datum data = { (char*)binary.c_str(), static_cast<int>(binary.length()) };
   return gdbm_store(out, key, data, GDBM_INSERT) == 0;
 }
 
