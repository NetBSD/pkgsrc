$NetBSD: patch-Iex_IexBaseExc.cpp,v 1.1 2013/12/26 15:59:27 tron Exp $

Fix build with C compilers other GCC.

--- Iex/IexBaseExc.cpp.orig	2013-10-15 23:55:09.000000000 +0100
+++ Iex/IexBaseExc.cpp	2013-12-26 15:17:54.000000000 +0000
@@ -149,8 +149,10 @@
 void
 iex_debugTrap()
 {
+#ifdef __GNUC__
     // how to in Linux?
     if (0 != ::getenv("IEXDEBUGTHROW"))
         __builtin_trap();
+#endif
 }
 #endif
