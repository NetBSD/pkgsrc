$NetBSD: patch-src_System_Console_Terminal_Posix.hsc,v 1.1 2022/05/10 09:47:37 jperkin Exp $

Include termios for struct winsize.

--- src/System/Console/Terminal/Posix.hsc.orig	2015-11-01 15:07:49.000000000 +0000
+++ src/System/Console/Terminal/Posix.hsc
@@ -18,6 +18,7 @@ import Prelude hiding (catch)
 import System.Posix.Types (Fd(Fd))
 
 #include <sys/ioctl.h>
+#include <termios.h>
 #include <unistd.h>
 
 
