$NetBSD: patch-openbsd_Platform.c,v 1.1 2022/05/07 07:35:06 nia Exp $

Ensure buffer for environment is large enough

https://github.com/htop-dev/htop/pull/997

--- openbsd/Platform.c.orig	2021-11-30 01:03:21.000000000 +0000
+++ openbsd/Platform.c
@@ -261,7 +261,13 @@ char* Platform_getProcessEnv(pid_t pid) 
    for (char** p = ptr; *p; p++) {
       size_t len = strlen(*p) + 1;
 
-      if (size + len > capacity) {
+      while (size + len > capacity) {
+         if (capacity > (SIZE_MAX / 2)) {
+            free(env);
+            env = NULL;
+            goto end;
+         }
+
          capacity *= 2;
          env = xRealloc(env, capacity);
       }
@@ -277,6 +283,7 @@ char* Platform_getProcessEnv(pid_t pid) 
       env[size + 1] = 0;
    }
 
+end:
    (void) kvm_close(kt);
    return env;
 }
