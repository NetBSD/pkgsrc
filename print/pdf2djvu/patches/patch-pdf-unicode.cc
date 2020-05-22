$NetBSD: patch-pdf-unicode.cc,v 1.1 2020/05/22 01:15:34 joerg Exp $

--- pdf-unicode.cc.orig	2020-05-16 19:53:42.159712563 +0000
+++ pdf-unicode.cc
@@ -124,7 +124,7 @@ std::string pdf::string_as_utf8(pdf::Obj
  * ===================
  */
 
-pdf::FullNFKC::FullNFKC(Unicode *unistr, int length)
+pdf::FullNFKC::FullNFKC(const Unicode *unistr, int length)
 : data(nullptr), length_(0)
 {
     assert(length >= 0);
@@ -140,7 +140,7 @@ pdf::FullNFKC::~FullNFKC()
  * ======================
  */
 
-pdf::MinimalNFKC::MinimalNFKC(Unicode *unistr, int length)
+pdf::MinimalNFKC::MinimalNFKC(const Unicode *unistr, int length)
 {
     this->string.append(unistr, length);
 }
