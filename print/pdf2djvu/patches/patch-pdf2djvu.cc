$NetBSD: patch-pdf2djvu.cc,v 1.1 2013/06/18 20:11:18 joerg Exp $

--- pdf2djvu.cc.orig	2013-06-18 19:40:16.000000000 +0000
+++ pdf2djvu.cc
@@ -210,6 +210,13 @@ public:
   friend Command &operator <<(Command &, const Component &);
 };
 
+Command &operator <<(Command &command, const File &arg)
+{
+  const std::string filename(arg);
+  command << filename;
+  return command;
+}
+
 Command &operator <<(Command &command, const Component &component)
 {
   command << *component.file;
