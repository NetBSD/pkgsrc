$NetBSD: patch-src_util_mpz.cpp,v 1.1 2016/07/16 04:02:13 markd Exp $

gcc6 fix

--- src/util/mpz.cpp.orig	2015-10-05 12:07:19.000000000 +0000
+++ src/util/mpz.cpp
@@ -134,7 +134,7 @@ mpz_manager<SYNCH>::mpz_manager():
 #endif
     
     mpz one(1);
-    set(m_two64, UINT64_MAX);
+    set(m_two64, (uint64)UINT64_MAX);
     add(m_two64, one, m_two64);
 }
 
