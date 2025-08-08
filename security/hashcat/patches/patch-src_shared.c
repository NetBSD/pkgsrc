$NetBSD: patch-src_shared.c,v 1.1 2025/08/08 07:24:00 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- src/shared.c.orig	2025-08-01 21:03:55.000000000 +0000
+++ src/shared.c
@@ -15,10 +15,13 @@
 #include <sys/cygwin.h>
 #endif
 
-#if defined (__APPLE__)
+#if defined (__APPLE__)   || defined (__OpenBSD__)   || defined (__NetBSD__) || \
+    defined (__FreeBSD__) || defined (__DragonFly__)
 #include <sys/sysctl.h>
+#if defined (__APPLE__)
 #include <mach/mach.h>
 #endif
+#endif
 
 #if defined (_WIN)
 #include <winsock2.h>
@@ -26,7 +29,8 @@
 
 #if defined (_POSIX)
 #include <sys/utsname.h>
-#if !defined (__APPLE__)
+#if !defined (__APPLE__)   && !defined (__OpenBSD__)   && !defined (__NetBSD__) && \
+    !defined (__FreeBSD__) && !defined (__DragonFly__)
 #include <sys/sysinfo.h>
 #endif
 #endif
@@ -311,9 +315,34 @@ int hc_asprintf (char **strp, const char
 #undef __WINDOWS__
 #endif
 
+#if defined (__OpenBSD__)
+static void *qsort_r_context;
+
+static int qsort_r_comparator (const void *a, const void *b)
+{
+    typedef int (*compare_fn_t) (const void *, const void *, void *);
+
+    compare_fn_t cmp = (compare_fn_t) qsort_r_context;
+
+    return cmp (a, b, NULL);
+}
+#endif
+
 void hc_qsort_r (void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *, void *), void *arg)
 {
+  #if defined (__OpenBSD__)
+
+  (void) arg; // unused, make compiler happy
+
+  qsort_r_context = (void *) compar;
+
+  qsort (base, nmemb, size, qsort_r_comparator);
+
+  #else
+
   sort_r (base, nmemb, size, compar, arg);
+
+  #endif
 }
 
 void *hc_bsearch_r (const void *key, const void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *, void *), void *arg)
@@ -940,11 +969,12 @@ int select_read_timeout (int sockfd, con
   fd_set fds;
 
   FD_ZERO (&fds);
-#if defined(_WIN)
+
+  #if defined (_WIN)
   FD_SET ((SOCKET)sockfd, &fds);
-#else
+  #else
   FD_SET (sockfd, &fds);
-#endif
+  #endif
 
   return select (sockfd + 1, &fds, NULL, NULL, &tv);
 }
@@ -959,11 +989,12 @@ int select_write_timeout (int sockfd, co
   fd_set fds;
 
   FD_ZERO (&fds);
-#if defined(_WIN)
+
+  #if defined (_WIN)
   FD_SET ((SOCKET)sockfd, &fds);
-#else
+  #else
   FD_SET (sockfd, &fds);
-#endif
+  #endif
 
   return select (sockfd + 1, NULL, &fds, NULL, &tv);
 }
@@ -1710,6 +1741,52 @@ bool get_free_memory (u64 *free_mem)
 
   return true;
 
+  #elif defined (__OpenBSD__)
+
+  struct uvmexp uvmexp;
+
+  size_t size = sizeof (uvmexp);
+
+  int mib[2] = {CTL_VM, VM_UVMEXP};
+
+  if (sysctl (mib, 2, &uvmexp, &size, NULL, 0) == -1) return false;
+
+  *free_mem = (uint64_t)(uvmexp.free * uvmexp.pagesize);
+
+  return true;
+
+  #elif defined (__FreeBSD__) || defined (__NetBSD__) || defined (__DragonFly__)
+
+  size_t len;
+
+  u64 pagesize = 0, free_pages = 0, cache_pages = 0, inactive_pages = 0;
+
+  len = sizeof (pagesize);
+
+  if (sysctlbyname ("hw.pagesize", &pagesize, &len, NULL, 0) == -1) return false;
+
+  len = sizeof (free_pages);
+
+  if (sysctlbyname ("vm.stats.vm.v_free_count", &free_pages, &len, NULL, 0) == -1) return false;
+
+  #if defined (__OpenBSD__) || defined (__FreeBSD__) || defined (__DragonFly__)
+
+  len = sizeof (cache_pages);
+
+  if (sysctlbyname ("vm.stats.vm.v_cache_count", &cache_pages, &len, NULL, 0) == -1) return false;
+
+  #endif // __OpenBSD__ || __FreeBSD__ || __DragonFly__
+
+  len = sizeof (inactive_pages);
+
+  if (sysctlbyname ("vm.stats.vm.v_inactive_count", &inactive_pages, &len, NULL, 0) == -1) return false;
+
+  u64 total_pages = free_pages + cache_pages + inactive_pages;
+
+  *free_mem = (u64) (total_pages * pagesize);
+
+  return true;
+
   #else
 
   struct sysinfo info;
