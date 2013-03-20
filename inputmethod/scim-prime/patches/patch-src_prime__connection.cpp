$NetBSD: patch-src_prime__connection.cpp,v 1.1 2013/03/20 06:54:42 obache Exp $

* prevent to use non portable sig_t

--- src/prime_connection.cpp.orig	2008-01-23 06:13:00.000000000 +0000
+++ src/prime_connection.cpp
@@ -223,7 +223,7 @@ PrimeConnection::close_connection (void)
         size_t len, remaining;
         len = remaining = strlen (command);
 
-        sig_t prev_handler = signal (SIGPIPE, handle_sigpipe);
+        void (*prev_handler)(int) = signal (SIGPIPE, handle_sigpipe);
 
 #if 0
         bool rv;
@@ -531,7 +531,7 @@ PrimeConnection::send_command (const cha
     str += "\n";
 
 
-    sig_t prev_handler = signal (SIGPIPE, handle_sigpipe);
+    void (*prev_handler)(int) = signal (SIGPIPE, handle_sigpipe);
 
     //
     // write the command
