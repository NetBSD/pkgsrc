$NetBSD: patch-lib_std_c.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

--- lib/std/c.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/c.zig
@@ -134,6 +134,7 @@ pub extern "c" fn futimens(fd: fd_t, tim
 pub extern "c" fn pthread_create(noalias newthread: *pthread_t, noalias attr: ?*const pthread_attr_t, start_routine: extern fn (?*c_void) ?*c_void, noalias arg: ?*c_void) c_int;
 pub extern "c" fn pthread_attr_init(attr: *pthread_attr_t) c_int;
 pub extern "c" fn pthread_attr_setstack(attr: *pthread_attr_t, stackaddr: *c_void, stacksize: usize) c_int;
+pub extern "c" fn pthread_attr_setguardsize(attr: *pthread_attr_t, guardsize: usize) c_int;
 pub extern "c" fn pthread_attr_destroy(attr: *pthread_attr_t) c_int;
 pub extern "c" fn pthread_self() pthread_t;
 pub extern "c" fn pthread_join(thread: pthread_t, arg_return: ?*?*c_void) c_int;
