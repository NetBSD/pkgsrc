$NetBSD: patch-dist_nimble_vendor_chronos_chronos_sendfile.nim,v 1.1 2026/11/07 22:43:07 wiz Exp $

NetBSD does not provide sendfile(2) (no libc symbol, no header declaration,
no man page). chronos grouped NetBSD with the BSDs that do, so the generated
code called an implicitly-declared function, which the pkgsrc compiler
wrapper turns into an error. Treat NetBSD like emscripten/haiku instead.

--- dist/nimble/vendor/chronos/chronos/sendfile.nim.orig
+++ dist/nimble/vendor/chronos/chronos/sendfile.nim
@@ -41,3 +41,3 @@
-elif defined(emscripten) or defined(haiku):
+elif defined(emscripten) or defined(haiku) or defined(netbsd):
 
   proc sendfile*(outfd, infd: int, offset: int, count: var int): int =
@@ -67,3 +67,2 @@
-elif defined(freebsd) or defined(openbsd) or defined(netbsd) or
-     defined(dragonflybsd):
+elif defined(freebsd) or defined(openbsd) or defined(dragonflybsd):
   import oserrno
