$NetBSD: patch-src_mp__std__bits.defs.hh,v 1.1 2013/02/09 21:29:24 wiz Exp $

Module: ppl/ppl
Branch: master
Commit: 9f843aecc23981aec6ed1eaa8be06e6786a47f0d
URL:    http://www.cs.unipr.it/git/gitweb.cgi?p=ppl/ppl.git;a=commit;h=9f843aecc23981aec6ed1eaa8be06e6786a47f0d

Author: Roberto Bagnara <bagnara at cs.unipr.it>
Date:   Wed Dec 19 08:42:19 2012 +0100

GMP version 5.1.0 (and, presumably, later versions) defines std::numeric_limits.

--- src/mp_std_bits.defs.hh.orig	2011-02-27 09:07:47.000000000 +0000
+++ src/mp_std_bits.defs.hh
@@ -39,6 +39,9 @@ void swap(mpz_class& x, mpz_class& y);
 #endif // defined(PPL_DOXYGEN_INCLUDE_IMPLEMENTATION_DETAILS)
 void swap(mpq_class& x, mpq_class& y);
 
+#if __GNU_MP_VERSION < 5 \
+  || (__GNU_MP_VERSION == 5 && __GNU_MP_VERSION_MINOR < 1)
+
 namespace std {
 
 #ifdef PPL_DOXYGEN_INCLUDE_IMPLEMENTATION_DETAILS
@@ -165,6 +168,9 @@ public:
 
 } // namespace std
 
+#endif // __GNU_MP_VERSION < 5
+       // || (__GNU_MP_VERSION == 5 && __GNU_MP_VERSION_MINOR < 1)
+
 #include "mp_std_bits.inlines.hh"
 
 #endif // !defined(PPL_mp_std_bits_defs_hh)
