$NetBSD: patch-misc_parallel.c,v 1.1 2018/03/07 12:34:55 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- misc/parallel.c.orig	2017-10-25 17:32:00.000000000 +0000
+++ misc/parallel.c
@@ -45,10 +45,10 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #else
 #error No sys/io.h; configure with --disable-parallel
 #endif
-#elif   defined __OpenBSD__                     // __linux__ && __GLIBC__
+#elif   defined __OpenBSD__ || defined __NetBSD__ // __linux__ && __GLIBC__
 #include <machine/sysarch.h>
 #include <sys/types.h>
-#elif   defined __BEOS__ || defined __FreeBSD__ // __OpenBSD__
+#elif   defined __BEOS__ || defined __FreeBSD__ // __OpenBSD__ || __NetBSD__
 #include <fcntl.h>
 #elif   defined AMIGA                           // __BEOS__ || __FreeBSD__
 #include <fcntl.h>
@@ -698,7 +698,7 @@ parport_open (unsigned short port)
     }                                           //  causes core dump
 #endif // __linux__ && (__i386__ || __x86_64__) && !USE_PPDEV
 
-#ifdef  __OpenBSD__ // || defined __NetBSD__, add after feature request ;-)
+#if     (defined __OpenBSD__ || defined __NetBSD__) && defined __i386__
   // We use i386_iopl() on OpenBSD for the same reasons we use iopl() on Linux
   //  (i386_set_ioperm() has the same limitation as ioperm()).
   if (i386_iopl (3) == -1)
@@ -709,6 +709,25 @@ parport_open (unsigned short port)
       exit (1);
     }
 #endif
+#ifdef  __x86_64__
+#ifdef  __OpenBSD__
+  if (amd64_iopl (3) == -1)
+    {
+      fputs ("ERROR: Could not set the I/O privilege level to 3\n"
+             "       (This program needs root privileges for the requested action)\n",
+             stderr);
+      exit (1);
+    }
+#elif   defined __NetBSD__
+  if (x86_64_iopl (3) == -1)
+    {
+      fputs ("ERROR: Could not set the I/O privilege level to 3\n"
+             "       (This program needs root privileges for the requested action)\n",
+             stderr);
+      exit (1);
+    }
+#endif
+#endif
 
 #if     (defined __i386__ || defined __x86_64__ || defined _WIN32) && !defined USE_PPDEV
 
