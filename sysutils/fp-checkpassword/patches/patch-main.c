$NetBSD: patch-main.c,v 1.1 2023/05/02 22:01:50 schmonz Exp $

Avoid clearenv(), not available on all platforms.

--- main.c.orig	2017-11-08 07:08:02.000000000 +0000
+++ main.c
@@ -41,6 +41,8 @@
 #define PORT 15408
 #define LOCALHOST "127.0.0.1"
 
+extern char **environ;
+
 int create_socket() {
     int sock;
     struct sockaddr_in dest;
@@ -146,7 +148,7 @@ int main(int argc, char** argv) {
     trimNewline(result);
 
     if (strcmp("success", result) == 0) {
-        clearenv();
+        environ = calloc(1, sizeof(*environ));
         readEnvironment(socket);
 
         closelog();
