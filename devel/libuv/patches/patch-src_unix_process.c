$NetBSD: patch-src_unix_process.c,v 1.2 2026/10/19 06:53:57 kikadf Exp $

Backport https://github.com/libuv/libuv/pull/5284

On NetBSD use fork instead of posix_spawn, while fix not available for:
PR kern/60653: posix_spawn(3) causes incorrect stack base information

--- src/unix/process.c.orig	2026-09-24 14:33:47.000000000 +0000
+++ src/unix/process.c
@@ -490,6 +490,9 @@ static void uv__spawn_init_posix_spawn(v
    * Unices in that it returns 0 instead of EACCES or ENOENT for paths
    * that don't exist. See https://github.com/libuv/libuv/issues/5240.
    */
+#elif defined(__NetBSD__)
+  /* PR kern/60653: posix_spawn(3) causes incorrect stack base information
+   */
 #else
 #if !defined(__linux__) && !defined(_AIX) && !defined(__PASE__)
   posix_spawn_works = 1;
@@ -610,11 +613,14 @@ static int uv__spawn_set_posix_spawn_fil
     const uv_process_options_t* options,
     int stdio_count,
     int (*pipes)[2]) {
+  int child_fds_storage[8];
+  int* child_fds;
   int fd;
   int fd2;
   int use_fd;
   int err;
 
+  child_fds = child_fds_storage;
   err = posix_spawn_file_actions_init(actions);
   if (err != 0) {
     /* If initialization fails, no need to de-init, just return */
@@ -633,14 +639,25 @@ static int uv__spawn_set_posix_spawn_fil
       goto error;
   }
 
-  /* Do not return ENOSYS after this point, as we may mutate pipes. */
+  if (stdio_count > (int) ARRAY_SIZE(child_fds_storage)) {
+    child_fds = uv__malloc(stdio_count * sizeof(*child_fds));
+    if (child_fds == NULL) {
+      err = ENOMEM;
+      goto error;
+    }
+  }
+
+  /* File actions only remap descriptors in the child. Keep the parent's
+   * descriptors intact for stream setup and cleanup. */
+  for (fd = 0; fd < stdio_count; fd++)
+    child_fds[fd] = pipes[fd][1];
 
   /* First duplicate low numbered fds, since it's not safe to duplicate them,
    * they could get replaced. Example: swapping stdout and stderr; without
    * this fd 2 (stderr) would be duplicated into fd 1, thus making both
    * stdout and stderr go to the same fd, which was not the intention. */
   for (fd = 0; fd < stdio_count; fd++) {
-    use_fd = pipes[fd][1];
+    use_fd = child_fds[fd];
 #if defined(__APPLE__) || defined(__linux__)
     if (use_fd < 0 || use_fd >= fd)
       continue;
@@ -656,24 +673,24 @@ static int uv__spawn_set_posix_spawn_fil
       /* If we were not setting POSIX_SPAWN_CLOEXEC_DEFAULT, we would need to
        * also consider whether fcntl(fd, F_GETFD) returned without the
        * FD_CLOEXEC flag set. */
-      if (pipes[fd2][1] == use_fd) {
+      if (child_fds[fd2] == use_fd) {
         use_fd++;
         fd2 = 0;
       }
     }
     err = posix_spawn_file_actions_adddup2(
       actions,
-      pipes[fd][1],
+      child_fds[fd],
       use_fd);
     assert(err != ENOSYS);
     if (err != 0)
       goto error;
-    pipes[fd][1] = use_fd;
+    child_fds[fd] = use_fd;
   }
 
   /* Second, move the descriptors into their respective places */
   for (fd = 0; fd < stdio_count; fd++) {
-    use_fd = pipes[fd][1];
+    use_fd = child_fds[fd];
     if (use_fd < 0) {
       if (fd >= 3)
         continue;
@@ -702,20 +719,21 @@ static int uv__spawn_set_posix_spawn_fil
     if (err != 0)
       goto error;
 
-    /* Make sure the fd is marked as non-blocking (state shared between child
-     * and parent). */
-    uv__nonblock_fcntl(use_fd, 0);
+    /* Make sure standard descriptors are blocking (state shared between
+     * child and parent). Leave other inherited descriptors unchanged. */
+    if (fd <= 2)
+      uv__nonblock_fcntl(pipes[fd][1], 0);
   }
 
   /* Finally, close all the superfluous descriptors */
   for (fd = 0; fd < stdio_count; fd++) {
-    use_fd = pipes[fd][1];
+    use_fd = child_fds[fd];
     if (use_fd < stdio_count)
       continue;
 
     /* Check if we already closed this. */
     for (fd2 = 0; fd2 < fd; fd2++) {
-      if (pipes[fd2][1] == use_fd)
+      if (child_fds[fd2] == use_fd)
           break;
     }
     if (fd2 < fd)
@@ -727,9 +745,13 @@ static int uv__spawn_set_posix_spawn_fil
       goto error;
   }
 
+  if (child_fds != child_fds_storage)
+    uv__free(child_fds);
   return 0;
 
 error:
+  if (child_fds != child_fds_storage)
+    uv__free(child_fds);
   (void) posix_spawn_file_actions_destroy(actions);
   return err;
 }
@@ -862,7 +884,6 @@ static int uv__spawn_and_init_child_posi
   if (err != 0)
     goto error;
 
-  /* This may mutate pipes. */
   err = uv__spawn_set_posix_spawn_file_actions(&actions,
                                                options,
                                                stdio_count,
