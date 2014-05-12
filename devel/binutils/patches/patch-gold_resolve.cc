$NetBSD: patch-gold_resolve.cc,v 1.1 2014/05/12 19:10:08 marino Exp $

 The gold linker is overly pedantic for dynamic references to symbols
 with hidden visibility.  It will spew error messages about weak symbols
 in libc.so that ld.bfd does not complain about. Until the bug is resolved
 disable the hidden symbol warnings.  These warning also cause > 200
 false failures in the gcc gnat.dg testsuite.

 https://sourceware.org/bugzilla/show_bug.cgi?id=15574

--- gold/resolve.cc.orig	2013-11-04 15:33:39.000000000 +0000
+++ gold/resolve.cc
@@ -276,8 +276,7 @@ Symbol_table::resolve(Sized_symbol<size>
       to->set_in_reg();
     }
   else if (st_shndx == elfcpp::SHN_UNDEF
-           && (to->visibility() == elfcpp::STV_HIDDEN
-               || to->visibility() == elfcpp::STV_INTERNAL))
+           && (to->visibility() == elfcpp::STV_INTERNAL))
     {
       // A dynamic object cannot reference a hidden or internal symbol
       // defined in another object.
