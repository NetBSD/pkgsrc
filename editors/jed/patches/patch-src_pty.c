$NetBSD: patch-src_pty.c,v 1.1 2023/12/19 23:56:00 gdt Exp $

Only do the I_PUSH stuff if it's defined.

--- src/pty.c.orig	2009-12-14 02:12:55.000000000 +0000
+++ src/pty.c
@@ -19,10 +19,12 @@
 #include <errno.h>
 
 #ifdef HAVE_GRANTPT
-# if !defined (__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__) && !defined(_AIX)
-#  define USE_SYSV_PTYS
-#  include <sys/types.h>
-#  include <stropts.h>
+# ifdef HAVE_SYS_STROPTS_H
+#  if !defined (__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__) && !defined(_AIX)
+#   define USE_SYSV_PTYS
+#   include <sys/types.h>
+#   include <stropts.h>
+#  endif
 # endif
 #endif
 
@@ -241,6 +243,7 @@ static int pty_open_slave_pty (char *sla
    if (-1 == (fd = signal_safe_open (slave_name, O_RDWR)))
      return -1;
 
+#ifdef I_PUSH
    if ((-1 == ioctl (fd, I_PUSH, "ptem"))
        || (-1 == ioctl (fd, I_PUSH, "ldterm")))
      {
@@ -261,6 +264,7 @@ static int pty_open_slave_pty (char *sla
 	  }
 # endif
      }
+#endif /* End of I_PUSH */
    *slave = fd;
    return 0;
 }
