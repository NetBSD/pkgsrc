$NetBSD: patch-libcult-1.4.2_cult_mm_bits_evptr.hxx,v 1.1 2013/03/24 16:58:28 joerg Exp $

--- libcult-1.4.2/cult/mm/bits/evptr.hxx.orig	2013-03-23 19:35:17.000000000 +0000
+++ libcult-1.4.2/cult/mm/bits/evptr.hxx
@@ -227,6 +227,7 @@ namespace Cult
         template <typename>
         friend class Transfer;
 
+      protected:
         mutable X* p_;
         mutable X const* cp_;
         mutable Counter* c_;
