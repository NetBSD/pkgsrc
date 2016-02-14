$NetBSD: patch-toolkit_xre_nsAppRunner.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

MacOS X < 10.6 had an undocumented behavior concerning execve(2)
inside a threaded process. If a process tried to call execve(2) and
had more than one active thread, the kernel returned ENOTSUP. So we
have to either fork(2) or vfork(2) before calling execve(2) to make
sure the caller is single-threaded as otherwise the application fails
to restart itself.

__mac_execve() in XNU 1228 (Darwin 9, MacOS X 10.5) had the
restriction:
http://www.opensource.apple.com/source/xnu/xnu-1228.15.4/bsd/kern/kern_exec.c

In XNU 1456 (Darwin 10, MacOS X 10.6) the multi-threaded check
disappeared:
http://www.opensource.apple.com/source/xnu/xnu-1456.1.26/bsd/kern/kern_exec.c

--- toolkit/xre/nsAppRunner.cpp.orig	2015-01-30 04:06:22.000000000 +0000
+++ toolkit/xre/nsAppRunner.cpp
@@ -1768,6 +1768,18 @@ static nsresult LaunchChild(nsINativeApp
   if (NS_FAILED(rv))
     return rv;
 
+#if defined(XP_DARWIN)
+  pid_t pid = vfork();
+  if (pid == 0) { // child
+    if (execv(exePath.get(), gRestartArgv) == -1) {
+      _exit(1);
+    }
+  }
+  else if (pid == -1) {
+    return NS_ERROR_FAILURE;
+  }
+#else
+
 #if defined(XP_UNIX)
   if (execv(exePath.get(), gRestartArgv) == -1)
     return NS_ERROR_FAILURE;
@@ -1781,6 +1793,7 @@ static nsresult LaunchChild(nsINativeApp
   if (failed || exitCode)
     return NS_ERROR_FAILURE;
 #endif // XP_UNIX
+#endif // XP_DARWIN
 #endif // WP_WIN
 #endif // WP_MACOSX
 #endif // MOZ_WIDGET_ANDROID
