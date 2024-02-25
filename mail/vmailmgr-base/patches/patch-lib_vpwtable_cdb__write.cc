$NetBSD: patch-lib_vpwtable_cdb__write.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Fix warnings.

--- lib/vpwtable/cdb_write.cc.orig	2024-02-20 03:14:13.278367363 +0000
+++ lib/vpwtable/cdb_write.cc
@@ -23,8 +23,8 @@
 class cdb_vpwtable_writer : public vpwtable_writer
 {
 private:
-  const mystring& tmpname;
-  const mystring& cdbname;
+  const mystring tmpname;
+  const mystring cdbname;
   cdb_writer out;
   bool opened;
 public:
