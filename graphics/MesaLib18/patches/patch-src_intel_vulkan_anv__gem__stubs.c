$NetBSD: patch-src_intel_vulkan_anv__gem__stubs.c,v 1.2 2019/05/01 19:31:46 maya Exp $

* Partially implement memfd_create() via mkostemp()

--- src/intel/vulkan/anv_gem_stubs.c.orig	2018-12-11 21:13:57.000000000 +0000
+++ src/intel/vulkan/anv_gem_stubs.c
@@ -31,7 +31,29 @@
 static inline int
 memfd_create(const char *name, unsigned int flags)
 {
+#if defined(SYS_memfd_create)
    return syscall(SYS_memfd_create, name, flags);
+#elif defined(__FreeBSD__)
+   return shm_open(SHM_ANON, flags | O_RDWR | O_CREAT, 0600);
+#else /* DragonFly, NetBSD, OpenBSD, Solaris */
+   char template[] = "/tmp/shmfd-XXXXXX";
+#ifdef HAVE_MKOSTEMP
+   int fd = mkostemp(template, flags);
+#else
+   int fd = mkstemp(template);
+   if (flags & O_CLOEXEC) {
+      int flags = fcntl(fd, F_GETFD);
+      if (flags != -1) {
+         flags |= FD_CLOEXEC;
+         (void) fcntl(fd, F_SETFD, &flags);
+      }
+   }
+#endif /* HAVE_MKOSTEMP */
+   if (fd >= 0)
+      unlink(template);
+
+   return fd;
+#endif /* __linux__ */
 }
 #endif
 
