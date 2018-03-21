$NetBSD: patch-src_debugger_debugger.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/debugger/debugger.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/debugger/debugger.cc
@@ -164,9 +164,9 @@ static void show_breakpoint(struct machi
 {
 	printf("%3i: 0x", i);
 	if (m->cpus[0]->is_32bit)
-		printf("%08"PRIx32, (uint32_t) m->breakpoints.addr[i]);
+		printf("%08" PRIx32, (uint32_t) m->breakpoints.addr[i]);
 	else
-		printf("%016"PRIx64, (uint64_t) m->breakpoints.addr[i]);
+		printf("%016" PRIx64, (uint64_t) m->breakpoints.addr[i]);
 	if (m->breakpoints.string[i] != NULL)
 		printf(" (%s)", m->breakpoints.string[i]);
 	printf("\n");
@@ -731,4 +731,3 @@ void debugger_init(struct emul *emul)
 	last_cmd_index = 0;
 	repeat_cmd[0] = '\0';
 }
-
