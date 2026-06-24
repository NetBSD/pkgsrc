$NetBSD: patch-system.hh,v 1.3 2026/06/24 21:57:36 wiz Exp $

Fix build with poppler 26.06.
From Arch.
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.01.0.patch?h=pdf2djvu
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.x.patch?h=pdf2djvu

--- system.hh.orig	2022-08-09 20:28:01.000000000 +0000
+++ system.hh
@@ -223,7 +223,7 @@ namespace encoding
   protected:
     const std::string &string;
   public:
-    explicit proxy<from, to>(const std::string &string)
+    explicit proxy(const std::string &string)
     : string(string)
     { }
     friend std::ostream &operator << <>(std::ostream &, const proxy<from, to> &);
