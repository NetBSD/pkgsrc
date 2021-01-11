$NetBSD: patch-extras_immodules_agent_scim-bridge-agent-signal-listener.cpp,v 1.1 2021/01/11 23:51:06 mef Exp $

scim-bridge-agent-signal-listener.cpp:67:57: error: invalid conversion from 'char' to 'const void*' [-fpermissive]
         send (pipe_in, '\0', sizeof (char), MSG_NOSIGNAL);
                                                         ^
In file included from scim-bridge-agent-signal-listener.cpp:27:0:
/usr/include/sys/socket.h:635:9: note:   initializing argument 2 of 'ssize_t send(int, const void*, size_t, int)'
 ssize_t send(int, const void *, size_t, int);
         ^~~~

--- extras/immodules/agent/scim-bridge-agent-signal-listener.cpp.orig	2021-01-12 07:34:31.247530264 +0900
+++ extras/immodules/agent/scim-bridge-agent-signal-listener.cpp	2021-01-12 07:37:39.629978933 +0900
@@ -64,7 +64,7 @@ static void sig_quit (int sig)
 {
     if (!signal_occurred) {
         signal_occurred = true;
-        send (pipe_in, '\0', sizeof (char), MSG_NOSIGNAL);
+        send (pipe_in, (const void *) '\0', sizeof (char), MSG_NOSIGNAL);
     }
 }
 
