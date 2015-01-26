$NetBSD: patch-zebra-kernel_socket.c,v 1.2 2015/01/26 00:06:50 gdt Exp $

This patch has already been applied upstream.

From 2fa9994ed80f1b5620cbebf040e85127992ec20d Mon Sep 17 00:00:00 2001
From: Greg Troxel <gdt@ir.bbn.com>
Date: Tue, 2 Dec 2014 14:51:49 -0500
Subject: [PATCH] zebra/kernel_socket.c: Use platform alignment.

Use the platform-provided RT_ROUNDUP macro to align sockaddrs on the
routing socket, rather than using hard-coded assumptions about
alignment.  Emit a warning if the OS doesn't define alignment macros.

Resolves failure of ripngd on NetBSD 6 i386, which changed alignment
to uint64_t from long.
---
 zebra/kernel_socket.c | 51 +++++++++++++++++++++++++++++++++++++++++----------
 1 file changed, 41 insertions(+), 10 deletions(-)

diff --git a/zebra/kernel_socket.c b/zebra/kernel_socket.c
index 3dbeb98..c2ede09 100644
--- zebra/kernel_socket.c
+++ zebra/kernel_socket.c
@@ -42,22 +42,53 @@ extern struct zebra_privs_t zserv_privs;
 extern struct zebra_t zebrad;
 
 /*
- * Given a sockaddr length, round it up to include pad bytes following
- * it.  Assumes the kernel pads to sizeof(long).
+ * Historically, the BSD routing socket has aligned data following a
+ * struct sockaddr to sizeof(long), which was 4 bytes on some
+ * platforms, and 8 bytes on others.  bytes.  NetBSD 6 changed the
+ * routing socket to align to sizeof(uint64_t), which is 8 bytes.  OS
+ * X appears to align to sizeof(int), which is 4 bytes.
  *
- * XXX: why is ROUNDUP(0) sizeof(long)?  0 is an illegal sockaddr
- * length anyway (< sizeof (struct sockaddr)), so this shouldn't
- * matter.
- * On OS X, both 32, 64bit syatems align on 4 byte boundary
+ * Alignment of zero-sized sockaddrs is nonsensical, but historically
+ * BSD defines RT_ROUNDUP(0) to be the alignment interval (rather than
+ * 0).  We follow this practice without questioning it, but it is a
+ * bug if quagga calls ROUNDUP with 0.
  */
+
+/*
+ * Because of these varying conventions, the only sane approach is for
+ * the <net/route.h> header to define a ROUNDUP macro.  We use the
+ * provided ROUNDUP macro when possible, and provide a workaround with
+ * a warning if not.
+ */
+#if defined(RT_ROUNDUP)
+#define ROUNDUP(a)	RT_ROUNDUP(a)
+#endif /* defined(RT_ROUNDUP) */
+
+/*
+ * If ROUNDUP is not defined in terms of platform-provided defines,
+ * attempt to cope with heuristics.
+ */
+#if !defined(ROUNDUP)
+
+/*
+ * It's a bug for a platform not to define rounding/alignment for
+ * sockaddrs on the routing socket.  This warning really is
+ * intentional, to provoke filing bug reports with operating systems
+ * that don't define RT_ROUNDUP or equivalent.
+ */
+#warning "net/route.h does not define RT_ROUNDUP; makeing unwarranted assumptions!"
+
 #ifdef __APPLE__
-#define ROUNDUP(a) \
-  ((a) > 0 ? (1 + (((a) - 1) | (sizeof(int) - 1))) : sizeof(int))
+#define ROUNDUP_TYPE	long
 #else
-#define ROUNDUP(a) \
-  ((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
+#define ROUNDUP_TYPE	int
 #endif
 
+#define ROUNDUP(a) \
+  ((a) > 0 ? (1 + (((a) - 1) | (sizeof(ROUNDUP_TYPE) - 1))) : sizeof(ROUNDUP_TYPE))
+
+#endif /* defined(ROUNDUP) */
+
 /*
  * Given a pointer (sockaddr or void *), return the number of bytes
  * taken up by the sockaddr and any padding needed for alignment.
-- 
2.1.0

