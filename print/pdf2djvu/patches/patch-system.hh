$NetBSD: patch-system.hh,v 1.1 2013/06/18 20:11:18 joerg Exp $

--- system.hh.orig	2013-06-18 19:44:44.000000000 +0000
+++ system.hh
@@ -136,6 +136,8 @@ public:
   friend std::ostream &operator<<(std::ostream &, const File &);
 };
 
+Command &operator <<(const Command &, const File& arg);
+
 class TemporaryFile : public File
 {
 private:
