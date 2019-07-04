$NetBSD: patch-src_interp.c,v 1.1 2019/07/04 10:17:34 nia Exp $

Fix C99 inline usage.

--- src/interp.c.orig	2011-11-05 11:40:53.000000000 +0000
+++ src/interp.c
@@ -232,7 +232,7 @@ ZFrame* call_routine(ZDWord* pc, ZStack*
   return newframe;
 }
 
-inline void store(ZStack* stack, int var, ZWord value)
+void store(ZStack* stack, int var, ZWord value)
 {
 #ifdef DEBUG
   printf_debug("Storing %i in Variable #%x\n", value, var);
