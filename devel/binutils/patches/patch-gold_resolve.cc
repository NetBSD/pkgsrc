$NetBSD: patch-gold_resolve.cc,v 1.2 2016/01/30 22:15:11 ryoon Exp $

 The gold linker is overly pedantic for dynamic references to symbols
 with hidden visibility.  It will spew error messages about weak symbols
 in libc.so that ld.bfd does not complain about. Until the bug is resolved
 disable the hidden symbol warnings.  These warning also cause > 200
 false failures in the gcc gnat.dg testsuite.

 https://sourceware.org/bugzilla/show_bug.cgi?id=15574

--- gold/resolve.cc.orig	2015-11-13 08:27:42.000000000 +0000
+++ gold/resolve.cc
@@ -284,8 +284,7 @@ Symbol_table::resolve(Sized_symbol<size>
       to->set_in_reg();
     }
   else if (st_shndx == elfcpp::SHN_UNDEF
-           && (to->visibility() == elfcpp::STV_HIDDEN
-               || to->visibility() == elfcpp::STV_INTERNAL))
+           && (to->visibility() == elfcpp::STV_INTERNAL))
     {
       // The symbol is hidden, so a reference from a shared object
       // cannot bind to it.  We tried issuing a warning in this case,
