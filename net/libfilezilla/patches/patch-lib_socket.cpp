$NetBSD: patch-lib_socket.cpp,v 1.2 2020/09/17 14:48:08 wiz Exp $

Spell struct correctly.

https://trac.filezilla-project.org/ticket/12280

--- lib/socket.cpp.orig	2020-08-21 13:35:14.000000000 +0000
+++ lib/socket.cpp
@@ -1678,8 +1678,8 @@ int socket::write(void const* buffer, un
 
 #if !defined(SO_NOSIGPIPE) && !defined(FZ_WINDOWS)
 	// Some systems have neither. Need to block signal
-	sigaction old_action;
-	sigaction action = {};
+	struct sigaction old_action;
+	struct sigaction action = {};
 	action.sa_handler = SIG_IGN;
 	int signal_set = sigaction(SIGPIPE, &action, &old_action);
 #endif
