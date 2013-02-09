$NetBSD: patch-src_mp__std__bits.cc,v 1.1 2013/02/09 21:29:24 wiz Exp $

Module: ppl/ppl
Branch: master
Commit: 9f843aecc23981aec6ed1eaa8be06e6786a47f0d
URL:    http://www.cs.unipr.it/git/gitweb.cgi?p=ppl/ppl.git;a=commit;h=9f843aecc23981aec6ed1eaa8be06e6786a47f0d

Author: Roberto Bagnara <bagnara at cs.unipr.it>
Date:   Wed Dec 19 08:42:19 2012 +0100

GMP version 5.1.0 (and, presumably, later versions) defines std::numeric_limits.

--- src/mp_std_bits.cc.orig	2011-02-27 09:07:47.000000000 +0000
+++ src/mp_std_bits.cc
@@ -26,6 +26,9 @@ site: http://www.cs.unipr.it/ppl/ . */
 #include <ppl-config.h>
 #include "mp_std_bits.defs.hh"
 
+#if __GNU_MP_VERSION < 5 \
+  || (__GNU_MP_VERSION == 5 && __GNU_MP_VERSION_MINOR < 1)
+
 const bool std::numeric_limits<mpz_class>::is_specialized;
 const int std::numeric_limits<mpz_class>::digits;
 const int std::numeric_limits<mpz_class>::digits10;
@@ -71,3 +74,6 @@ const bool std::numeric_limits<mpq_class
 const bool std::numeric_limits<mpq_class>::traps;
 const bool std::numeric_limits<mpq_class>::tininess_before;
 const std::float_round_style std::numeric_limits<mpq_class>::round_style;
+
+#endif // __GNU_MP_VERSION < 5
+       // || (__GNU_MP_VERSION == 5 && __GNU_MP_VERSION_MINOR < 1)
