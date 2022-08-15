$NetBSD: patch-truss_count.c,v 1.1 2022/08/15 23:04:38 tnn Exp $

https://github.com/krytarowski/picotrace/commit/b2b7d9922f189021dff289d306413058b594811d

--- truss/count.c.orig	2020-03-18 15:39:21.000000000 +0000
+++ truss/count.c
@@ -140,7 +140,7 @@ count_startup(pid_t pid)
 	int op = PT_LWPNEXT;
 #else
 	struct ptrace_lwpinfo pl;
-	int op = PT_LWPNEXT;
+	int op = PT_LWPINFO;
 #endif
 
 	ptrace_event_t pe;
