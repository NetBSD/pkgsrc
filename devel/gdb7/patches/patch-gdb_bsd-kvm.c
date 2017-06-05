$NetBSD: patch-gdb_bsd-kvm.c,v 1.1 2017/06/05 10:41:28 maya Exp $

(1) (unknown yet)
(2) +#include <sys/signal.h> part:
NetBSD/i386 5.2 has following problem without sys/signal.h
from bsd-kvm.c:36:
/usr/include/sys/signalvar.h:56: error: field 'sd_sigact' has incomplete type
/usr/include/sys/signalvar.h:59: error: 'NSIG' undeclared here (not in a function)
gmake[2]: *** [bsd-kvm.o] Error 1

--- gdb/bsd-kvm.c.orig	2015-02-19 11:58:07.000000000 +0000
+++ gdb/bsd-kvm.c
@@ -28,7 +28,12 @@
 #include "gdbthread.h"
 
 #include <fcntl.h>
+#include <stddef.h>
 #include <kvm.h>
+#define _KMEMUSER 1
+#include <sys/signal.h>
+#include <lwp.h>
+#include <sys/lwp.h>
 #ifdef HAVE_NLIST_H
 #include <nlist.h>
 #endif
@@ -36,6 +41,7 @@
 #include "readline/readline.h"
 #include <sys/param.h>
 #include <sys/proc.h>
+#include <sys/types.h>
 #include <sys/user.h>
 
 #include "bsd-kvm.h"
