$NetBSD: patch-src_stk_kernel_stk__looper.cpp,v 1.1 2026/01/03 10:52:03 wiz Exp $

g++ does not like double definition of default parameters.

--- src/stk/kernel/stk_looper.cpp.orig	2001-07-15 23:26:19.000000000 +0200
+++ src/stk/kernel/stk_looper.cpp	2006-03-09 14:59:00.000000000 +0100
@@ -39,7 +39,7 @@ int Stk2_Messages::PollMessage(Stk2_Mess
 
 /* ---------------------- Looper ----------------------------- */
 
-Stk2_Looper::Stk2_Looper(int freq=25)
+Stk2_Looper::Stk2_Looper(int freq)
         :Stk_Thread()
 {
     frequency=freq;
