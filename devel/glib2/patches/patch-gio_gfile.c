$NetBSD: patch-gio_gfile.c,v 1.4 2018/05/26 13:25:55 schmonz Exp $

Fix build on CentOS 6 (at least) with upstream patch for bug 795133.

--- gio/gfile.c.orig	2018-03-12 16:23:37.000000000 +0000
+++ gio/gfile.c
@@ -3012,6 +3012,7 @@ splice_stream_with_progress (GInputStrea
   if (!g_unix_open_pipe (buffer, FD_CLOEXEC, error))
     return FALSE;
 
+#if defined(F_SETPIPE_SZ) && defined(F_GETPIPE_SZ)
   /* Try a 1MiB buffer for improved throughput. If that fails, use the default
    * pipe size. See: https://bugzilla.gnome.org/791457 */
   buffer_size = fcntl (buffer[1], F_SETPIPE_SZ, 1024 * 1024);
@@ -3029,6 +3030,13 @@ splice_stream_with_progress (GInputStrea
           goto out;
         }
     }
+#else
+  /* If #F_GETPIPE_SZ isn’t available, assume we’re on Linux < 2.6.35,
+   * but ≥ 2.6.11, meaning the pipe capacity is 64KiB. Ignore the possibility of
+   * running on Linux < 2.6.11 (where the capacity was the system page size,
+   * typically 4KiB) because it’s ancient. See pipe(7). */
+  buffer_size = 1024 * 64;
+#endif
 
   g_assert (buffer_size > 0);
 
