$NetBSD: patch-common_scheduler.cc,v 1.1 2013/03/03 01:07:54 joerg Exp $

--- common/scheduler.cc.orig	2013-03-02 23:41:43.000000000 +0000
+++ common/scheduler.cc
@@ -185,6 +185,12 @@ Scheduler::reset()
 	clock_ = SCHED_START;
 }
 
+#ifdef MEMDEBUG_SIMULATIONS
+extern "C++" {
+	extern MemTrace *globalMemTrace;
+}
+#endif
+
 int 
 Scheduler::command(int argc, const char*const* argv)
 {
@@ -211,7 +217,6 @@ Scheduler::command(int argc, const char*
 
 		} else if (strcmp(argv[1], "clearMemTrace") == 0) {
 #ifdef MEMDEBUG_SIMULATIONS
-			extern MemTrace *globalMemTrace;
 			if (globalMemTrace)
 				globalMemTrace->diff("Sim.");
 #endif
