$NetBSD: patch-src_System_Console_Terminal_Posix.hsc,v 1.2 2023/01/24 17:07:08 pho Exp $

Include termios for struct winsize.

--- src/System/Console/Terminal/Posix.hsc.orig	2022-03-20 20:28:25.000000000 +0000
+++ src/System/Console/Terminal/Posix.hsc
@@ -19,6 +19,7 @@ import Prelude hiding (catch)
 import System.Posix.Types (Fd(Fd))
 
 #include <sys/ioctl.h>
+#include <termios.h>
 #include <unistd.h>
 
 #if defined(__GLASGOW_HASKELL__) && (__GLASGOW_HASKELL__ < 800)
