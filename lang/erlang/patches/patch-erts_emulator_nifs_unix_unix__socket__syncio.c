$NetBSD: patch-erts_emulator_nifs_unix_unix__socket__syncio.c,v 1.2 2023/06/27 08:33:10 adam Exp $

Expose required socket features on SunOS.

--- erts/emulator/nifs/unix/unix_socket_syncio.c.orig	2023-06-08 05:33:54.000000000 +0000
+++ erts/emulator/nifs/unix/unix_socket_syncio.c
@@ -29,6 +29,15 @@
 #    include "config.h"
 #endif
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE	500
+#  else
+#define _XOPEN_SOURCE	600
+#  endif
+#define	__EXTENSIONS__
+#endif
+
 #ifdef ESOCK_ENABLE
 
 /* If we HAVE_SCTP_H and Solaris, we need to define the following in
