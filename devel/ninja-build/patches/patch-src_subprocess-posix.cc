$NetBSD: patch-src_subprocess-posix.cc,v 1.3 2020/04/21 07:48:55 dsainty Exp $

Support a shell other than /bin/sh as a workaround for MacOS X. 

Under MacOS X the LD_LIBRARY_PATH variable is unset by the build system
running executables under /bin (namely /bin/sh).  This is part of MacOS X
System Integrity Protection.

Because many (most?) users of ninja/meson seem to need hacks involving
LD_LIBRARY_PATH, use a non-SIP-triggering shell under MacOS X.

--- src/subprocess-posix.cc.orig	2019-11-24 01:57:30.000000000 +1300
+++ src/subprocess-posix.cc	2019-11-24 01:58:15.000000000 +1300
@@ -110,8 +110,10 @@
   if (err != 0)
     Fatal("posix_spawnattr_setflags: %s", strerror(err));
 
-  const char* spawned_args[] = { "/bin/sh", "-c", command.c_str(), NULL };
-  err = posix_spawn(&pid_, "/bin/sh", &action, &attr,
+#define xstr(s) str(s)
+#define str(s) #s
+  const char* spawned_args[] = { xstr(NINJA_SHELL), "-c", command.c_str(), NULL };
+  err = posix_spawn(&pid_, xstr(NINJA_SHELL), &action, &attr,
         const_cast<char**>(spawned_args), environ);
   if (err != 0)
     Fatal("posix_spawn: %s", strerror(err));
