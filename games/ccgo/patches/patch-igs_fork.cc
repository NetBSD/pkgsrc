$NetBSD: patch-igs_fork.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/fork.cc.orig	2015-05-23 14:48:57.000000000 +0000
+++ igs/fork.cc
@@ -27,7 +27,11 @@ extern "C" {
 #include <sys/types.h>
 #include <sys/fcntl.h>
 #include <sys/wait.h>
+#ifdef __sun
+#include <fcntl.h>
+#endif
 #include <unistd.h>
+#include <signal.h>
 }
 
 using namespace igs;
@@ -151,7 +155,7 @@ bool Fork::open_conn(const std::string &
 		close(c2p[0]);
 		close(c2p[1]);
 		close(2); // close cerr
-		const char * shell = "/bin/bash";
+		const char * shell = "/bin/sh";
 		std::string c = std::string ("exec ") + n;
 		execl(shell, shell, "-c", c.c_str(), (void *) 0);
 		std::cerr << "Fail to fork: " << n << std::endl;
