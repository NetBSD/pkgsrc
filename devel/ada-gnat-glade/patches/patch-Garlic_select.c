$NetBSD: patch-Garlic_select.c,v 1.1 2025/07/11 06:17:39 dkazankov Exp $

Fix link time version warning on NetBSD

--- /dev/null
+++ Garlic/select.c
@@ -0,0 +1,7 @@
+#include <sys/select.h>
+int
+__netbsd_select(int nfds, fd_set * restrict readfds, fd_set * restrict writefds,
+    fd_set * restrict exceptfds, struct timeval * restrict timeout)
+{
+    return select(nfds, readfds, writefds, exceptfds, timeout);
+}
