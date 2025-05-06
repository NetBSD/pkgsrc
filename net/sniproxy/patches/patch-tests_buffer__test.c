$NetBSD: patch-tests_buffer__test.c,v 1.1 2025/05/06 15:49:16 schmonz Exp $

Allocate enough buffer for header sizes seen in common webservers.
https://github.com/renaudallard/sniproxy/commit/1a504817462209ecaa2f62ff925b58852e22f564

--- tests/buffer_test.c.orig	2024-07-02 15:36:27.000000000 +0000
+++ tests/buffer_test.c
@@ -127,7 +127,7 @@ static void test4() {
     struct Buffer *buffer;
     int read_fd, write_fd;
 
-    buffer = new_buffer(4096, EV_DEFAULT);
+    buffer = new_buffer(16384, EV_DEFAULT);
 
     read_fd = open("/dev/zero", O_RDONLY);
     if (read_fd < 0) {
@@ -155,7 +155,7 @@ static void test_buffer_coalesce() {
     char output[sizeof(input)];
     int len;
 
-    buffer = new_buffer(4096, EV_DEFAULT);
+    buffer = new_buffer(16384, EV_DEFAULT);
     len = buffer_push(buffer, input, sizeof(input));
     assert(len == sizeof(input));
 
