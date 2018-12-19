$NetBSD: patch-src_lib_debug.c,v 1.1 2018/12/19 22:52:32 manu Exp $

Fix startup crash when running outside of gdb on BSD systems.

From upstream https://github.com/FreeRADIUS/freeradius-server/commit/1f8cd27b78c011826bc0744debb4ed60b3f0584a

--- src/lib//debug.c.orig	2018-12-16 03:31:31.909930476 +0100
+++ src/lib//debug.c	2018-12-19 10:05:49.848809433 +0100
@@ -105,13 +105,21 @@
 
 static TALLOC_CTX *talloc_null_ctx;
 static TALLOC_CTX *talloc_autofree_ctx;
 
+/*
+ * On BSD systems, ptrace(PT_DETACH) uses a third argument for
+ * resume address, with the magic value (void *)1 to resume where
+ * process stopped. Specifying NULL there leads to a crash because
+ * process resumes at address 0.
+ */  
 #ifdef HAVE_SYS_PTRACE_H
 #  ifdef __linux__
 #    define _PTRACE(_x, _y) ptrace(_x, _y, NULL, NULL)
+#    define _PTRACE_DETACH(_x) ptrace(PT_DETACH, _x, NULL, NULL)
 #  else
 #    define _PTRACE(_x, _y) ptrace(_x, _y, NULL, 0)
+#    define _PTRACE_DETACH(_x) ptrace(PT_DETACH, _x, (void *)1, NULL)
 #  endif
 
 #  ifdef HAVE_CAPABILITY_H
 #    include <sys/capability.h>
@@ -205,9 +213,9 @@
 				fprintf(stderr, "Writing ptrace status to parent failed: %s", fr_syserror(errno));
 			}
 
 			/* Detach */
-			_PTRACE(PT_DETACH, ppid);
+			_PTRACE_DETACH(ppid);
 			exit(0);
 		}
 
 		ret = DEBUG_STATE_ATTACHED;
