$NetBSD: patch-src_slurmctld_trigger__mgr.c,v 1.1 2026/01/07 18:30:07 adam Exp $

NetBSD doesn't have setresuid().

--- src/slurmctld/trigger_mgr.c.orig	2026-01-07 14:14:39.292864749 +0000
+++ src/slurmctld/trigger_mgr.c
@@ -1350,10 +1350,12 @@ static void _trigger_run_program(trig_mg
 			error("trigger: setgid: %m");
 			exit(1);
 		}
+#if !defined(__APPLE__) && !defined(__NetBSD__)
 		if ((setresuid(uid, uid, -1) == -1) && !run_as_self) {
 			error("trigger: setresuid: %m");
 			exit(1);
 		}
+#endif
 		execv(program, args);
 		exit(1);
 	} else {
