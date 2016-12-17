$NetBSD: patch-gmp_device.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- gmp/device.cc.orig	2015-05-23 14:48:57.000000000 +0000
+++ gmp/device.cc
@@ -26,7 +26,11 @@
 extern "C" {
 #include <sys/fcntl.h>
 #include <sys/wait.h>
+#ifdef __sun
+#include <fcntl.h>
+#endif
 #include <unistd.h>
+#include <signal.h>
 }
 
 using namespace gmp;
@@ -370,7 +374,7 @@ bool Device::fork_child(const std::strin
 		close(c2p[0]);
 		close(c2p[1]);
 		// close(2); // close cerr
-		const char * shell = "/bin/bash";
+		const char * shell = "/bin/sh";
 		std::string c = std::string("exec ") + n;
 		execl(shell, shell, "-c", c.c_str(), (void *) 0);
 		// exec failed!
