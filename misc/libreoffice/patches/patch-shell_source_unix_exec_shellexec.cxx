$NetBSD: patch-shell_source_unix_exec_shellexec.cxx,v 1.1 2021/04/05 10:17:21 ryoon Exp $

* Fix xdg-open path. PR pkg/56092
  https://bugs.documentfoundation.org/show_bug.cgi?id=108591

--- shell/source/unix/exec/shellexec.cxx.orig	2021-03-24 16:28:10.000000000 +0000
+++ shell/source/unix/exec/shellexec.cxx
@@ -172,7 +172,7 @@ void SAL_CALL ShellExec::execute( const 
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
