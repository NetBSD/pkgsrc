$NetBSD: patch-pdf-unicode.hh,v 1.1 2020/05/22 01:15:34 joerg Exp $

--- pdf-unicode.hh.orig	2020-05-16 19:53:15.675224456 +0000
+++ pdf-unicode.hh
@@ -58,7 +58,7 @@ namespace pdf
         Unicode* data;
         int length_;
     public:
-        explicit FullNFKC(Unicode *, int length);
+        explicit FullNFKC(const Unicode *, int length);
         ~FullNFKC();
         int length() const
         {
@@ -79,7 +79,7 @@ namespace pdf
     protected:
         std::basic_string<Unicode> string;
     public:
-        explicit MinimalNFKC(Unicode *, int length);
+        explicit MinimalNFKC(const Unicode *, int length);
         int length() const;
         operator const Unicode*() const;
     };
