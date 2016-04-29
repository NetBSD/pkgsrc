$NetBSD: patch-psutil___psutil__bsd.c,v 1.6 2016/04/29 15:33:57 prlw1 Exp $

MNT_RELATIME and MNT_EXTATTR are not available on NetBSD-5.

https://github.com/giampaolo/psutil/pull/812

--- psutil/_psutil_bsd.c.orig	2016-03-12 17:12:23.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -712,16 +712,20 @@ psutil_disk_partitions(PyObject *self, P
             strlcat(opts, ",union", sizeof(opts));
         if (flags & MNT_NOCOREDUMP)
             strlcat(opts, ",nocoredump", sizeof(opts));
+#if defined(MNT_RELATIME)
         if (flags & MNT_RELATIME)
             strlcat(opts, ",relatime", sizeof(opts));
+#endif
         if (flags & MNT_IGNORE)
             strlcat(opts, ",ignore", sizeof(opts));
 #if defined(MNT_DISCARD)
         if (flags & MNT_DISCARD)
             strlcat(opts, ",discard", sizeof(opts));
 #endif
+#if defined(MNT_EXTATTR)
         if (flags & MNT_EXTATTR)
             strlcat(opts, ",extattr", sizeof(opts));
+#endif
         if (flags & MNT_LOG)
             strlcat(opts, ",log", sizeof(opts));
         if (flags & MNT_SYMPERM)
