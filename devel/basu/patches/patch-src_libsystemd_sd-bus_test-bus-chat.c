$NetBSD: patch-src_libsystemd_sd-bus_test-bus-chat.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/test-bus-chat.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/test-bus-chat.c
@@ -30,7 +30,7 @@ static int object_callback(sd_bus_messag
 
                 r = sd_bus_reply_method_return(m, NULL);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to send reply: %m");
+                        return log_error_errno(r, "Failed to send reply");
 
                 return 1;
         }
@@ -48,19 +48,19 @@ static int server_init(sd_bus **_bus) {
 
         r = sd_bus_open_user_with_description(&bus, "my bus!");
         if (r < 0) {
-                log_error_errno(r, "Failed to connect to user bus: %m");
+                log_error_errno(r, "Failed to connect to user bus");
                 goto fail;
         }
 
         r = sd_bus_get_bus_id(bus, &id);
         if (r < 0) {
-                log_error_errno(r, "Failed to get server ID: %m");
+                log_error_errno(r, "Failed to get server ID");
                 goto fail;
         }
 
         r = sd_bus_get_unique_name(bus, &unique);
         if (r < 0) {
-                log_error_errno(r, "Failed to get unique name: %m");
+                log_error_errno(r, "Failed to get unique name");
                 goto fail;
         }
 
@@ -73,25 +73,25 @@ static int server_init(sd_bus **_bus) {
 
         r = sd_bus_request_name(bus, "org.freedesktop.systemd.test", 0);
         if (r < 0) {
-                log_error_errno(r, "Failed to acquire name: %m");
+                log_error_errno(r, "Failed to acquire name");
                 goto fail;
         }
 
         r = sd_bus_add_fallback(bus, NULL, "/foo/bar", object_callback, NULL);
         if (r < 0) {
-                log_error_errno(r, "Failed to add object: %m");
+                log_error_errno(r, "Failed to add object");
                 goto fail;
         }
 
         r = sd_bus_match_signal(bus, NULL, NULL, NULL, "foo.bar", "Notify", match_callback, NULL);
         if (r < 0) {
-                log_error_errno(r, "Failed to request match: %m");
+                log_error_errno(r, "Failed to request match");
                 goto fail;
         }
 
         r = sd_bus_add_match(bus, NULL, "type='signal',interface='org.freedesktop.DBus',member='NameOwnerChanged'", match_callback, NULL);
         if (r < 0) {
-                log_error_errno(r, "Failed to add match: %m");
+                log_error_errno(r, "Failed to add match");
                 goto fail;
         }
 
@@ -116,14 +116,14 @@ static int server(sd_bus *bus) {
 
                 r = sd_bus_process(bus, &m);
                 if (r < 0) {
-                        log_error_errno(r, "Failed to process requests: %m");
+                        log_error_errno(r, "Failed to process requests");
                         goto fail;
                 }
 
                 if (r == 0) {
                         r = sd_bus_wait(bus, (uint64_t) -1);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to wait: %m");
+                                log_error_errno(r, "Failed to wait");
                                 goto fail;
                         }
 
@@ -148,7 +148,7 @@ static int server(sd_bus *bus) {
 
                         r = sd_bus_message_read(m, "s", &hello);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to get parameter: %m");
+                                log_error_errno(r, "Failed to get parameter");
                                 goto fail;
                         }
 
@@ -162,14 +162,14 @@ static int server(sd_bus *bus) {
 
                         r = sd_bus_reply_method_return(m, "s", lowercase);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
                 } else if (sd_bus_message_is_method_call(m, "org.freedesktop.systemd.test", "ExitClient1")) {
 
                         r = sd_bus_reply_method_return(m, NULL);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
 
@@ -178,7 +178,7 @@ static int server(sd_bus *bus) {
 
                         r = sd_bus_reply_method_return(m, NULL);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
 
@@ -189,7 +189,7 @@ static int server(sd_bus *bus) {
 
                         r = sd_bus_reply_method_return(m, NULL);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
 
@@ -199,21 +199,21 @@ static int server(sd_bus *bus) {
 
                         r = sd_bus_message_read(m, "h", &fd);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to get parameter: %m");
+                                log_error_errno(r, "Failed to get parameter");
                                 goto fail;
                         }
 
                         log_info("Received fd=%d", fd);
 
                         if (write(fd, &x, 1) < 0) {
-                                log_error_errno(errno, "Failed to write to fd: %m");
+                                log_error_errno(errno, "Failed to write to fd");
                                 safe_close(fd);
                                 goto fail;
                         }
 
                         r = sd_bus_reply_method_return(m, NULL);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
 
@@ -223,7 +223,7 @@ static int server(sd_bus *bus) {
                                         m,
                                         &SD_BUS_ERROR_MAKE_CONST(SD_BUS_ERROR_UNKNOWN_METHOD, "Unknown method."));
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
                 }
@@ -251,7 +251,7 @@ static void* client1(void*p) {
 
         r = sd_bus_open_user(&bus);
         if (r < 0) {
-                log_error_errno(r, "Failed to connect to user bus: %m");
+                log_error_errno(r, "Failed to connect to user bus");
                 goto finish;
         }
 
@@ -266,20 +266,20 @@ static void* client1(void*p) {
                         "s",
                         "HELLO");
         if (r < 0) {
-                log_error_errno(r, "Failed to issue method call: %m");
+                log_error_errno(r, "Failed to issue method call");
                 goto finish;
         }
 
         r = sd_bus_message_read(reply, "s", &hello);
         if (r < 0) {
-                log_error_errno(r, "Failed to get string: %m");
+                log_error_errno(r, "Failed to get string");
                 goto finish;
         }
 
         assert_se(streq(hello, "hello"));
 
         if (pipe2(pp, O_CLOEXEC|O_NONBLOCK) < 0) {
-                log_error_errno(errno, "Failed to allocate pipe: %m");
+                log_error_errno(errno, "Failed to allocate pipe");
                 r = -errno;
                 goto finish;
         }
@@ -297,7 +297,7 @@ static void* client1(void*p) {
                         "h",
                         pp[1]);
         if (r < 0) {
-                log_error_errno(r, "Failed to issue method call: %m");
+                log_error_errno(r, "Failed to issue method call");
                 goto finish;
         }
 
@@ -321,7 +321,7 @@ finish:
                                 "org.freedesktop.systemd.test",
                                 "ExitClient1");
                 if (r < 0)
-                        log_error_errno(r, "Failed to allocate method call: %m");
+                        log_error_errno(r, "Failed to allocate method call");
                 else
                         sd_bus_send(bus, q, NULL);
 
@@ -333,7 +333,7 @@ finish:
 static int quit_callback(sd_bus_message *m, void *userdata, sd_bus_error *ret_error) {
         bool *x = userdata;
 
-        log_error_errno(sd_bus_message_get_errno(m), "Quit callback: %m");
+        log_error_errno(sd_bus_message_get_errno(m), "Quit callback");
 
         *x = 1;
         return 1;
@@ -349,7 +349,7 @@ static void* client2(void*p) {
 
         r = sd_bus_open_user(&bus);
         if (r < 0) {
-                log_error_errno(r, "Failed to connect to user bus: %m");
+                log_error_errno(r, "Failed to connect to user bus");
                 goto finish;
         }
 
@@ -361,7 +361,7 @@ static void* client2(void*p) {
                         "org.object.test",
                         "Foobar");
         if (r < 0) {
-                log_error_errno(r, "Failed to allocate method call: %m");
+                log_error_errno(r, "Failed to allocate method call");
                 goto finish;
         }
 
@@ -380,7 +380,7 @@ static void* client2(void*p) {
                         "foo.bar",
                         "Notify");
         if (r < 0) {
-                log_error_errno(r, "Failed to allocate signal: %m");
+                log_error_errno(r, "Failed to allocate signal");
                 goto finish;
         }
 
@@ -400,7 +400,7 @@ static void* client2(void*p) {
                         "org.freedesktop.DBus.Peer",
                         "GetMachineId");
         if (r < 0) {
-                log_error_errno(r, "Failed to allocate method call: %m");
+                log_error_errno(r, "Failed to allocate method call");
                 goto finish;
         }
 
@@ -412,7 +412,7 @@ static void* client2(void*p) {
 
         r = sd_bus_message_read(reply, "s", &mid);
         if (r < 0) {
-                log_error_errno(r, "Failed to parse machine ID: %m");
+                log_error_errno(r, "Failed to parse machine ID");
                 goto finish;
         }
 
@@ -428,7 +428,7 @@ static void* client2(void*p) {
                         "org.freedesktop.systemd.test",
                         "Slow");
         if (r < 0) {
-                log_error_errno(r, "Failed to allocate method call: %m");
+                log_error_errno(r, "Failed to allocate method call");
                 goto finish;
         }
 
@@ -450,7 +450,7 @@ static void* client2(void*p) {
                         "org.freedesktop.systemd.test",
                         "Slow");
         if (r < 0) {
-                log_error_errno(r, "Failed to allocate method call: %m");
+                log_error_errno(r, "Failed to allocate method call");
                 goto finish;
         }
 
@@ -463,13 +463,13 @@ static void* client2(void*p) {
         while (!quit) {
                 r = sd_bus_process(bus, NULL);
                 if (r < 0) {
-                        log_error_errno(r, "Failed to process requests: %m");
+                        log_error_errno(r, "Failed to process requests");
                         goto finish;
                 }
                 if (r == 0) {
                         r = sd_bus_wait(bus, (uint64_t) -1);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to wait: %m");
+                                log_error_errno(r, "Failed to wait");
                                 goto finish;
                         }
                 }
@@ -489,7 +489,7 @@ finish:
                                 "org.freedesktop.systemd.test",
                                 "ExitClient2");
                 if (r < 0) {
-                        log_error_errno(r, "Failed to allocate method call: %m");
+                        log_error_errno(r, "Failed to allocate method call");
                         goto finish;
                 }
 
