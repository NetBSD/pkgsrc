$NetBSD: patch-vendor_spawn_src_spawn__stubs.c,v 1.1 2026/04/14 09:15:00 jperkin Exp $

Retry read() on EINTR.  Reported upstream as
https://github.com/ocaml/dune/issues/14182

--- vendor/spawn/src/spawn_stubs.c.orig	2026-04-01 17:26:23.000000000 +0000
+++ vendor/spawn/src/spawn_stubs.c
@@ -750,7 +750,10 @@ CAMLprim value spawn_unix(value v_env,
     got_error = 1;
     set_error(&failure, errno_after_forking, "vfork", NOTHING);
   } else {
-    intnat res = read(result_pipe[0], &failure, sizeof(failure));
+    intnat res;
+    do {
+      res = read(result_pipe[0], &failure, sizeof(failure));
+    } while (res == -1 && errno == EINTR);
     /* If the sub-process exec successfully, the write end of the
        error pipe is closed (as it has the [O_CLOEXEC] flag set) and
        [read] returns [0].
