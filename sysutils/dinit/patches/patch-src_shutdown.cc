$NetBSD: patch-src_shutdown.cc,v 1.1 2025/01/29 05:13:03 imil Exp $

Implement shutdown for NetBSD

--- src/shutdown.cc.orig	2025-01-07 12:31:49.000000000 +0000
+++ src/shutdown.cc
@@ -496,7 +496,11 @@ void do_system_shutdown(shutdown_type_t 
     
     sub_buf.append("Issuing shutdown via kernel...\n");
     loop.poll();  // give message a chance to get to console
+#ifdef __NetBSD__
+    reboot(reboot_type, NULL);
+#else
     reboot(reboot_type);
+#endif
 }
 
 // Watcher for subprocess output.
@@ -637,7 +641,11 @@ static loop_t::child_proc_watcher::proc_
 static void unmount_disks(loop_t &loop, subproc_buffer &sub_buf)
 {
     try {
+#ifdef __NetBSD__
+        const char * unmount_args[] = { "/sbin/umount", "-a", nullptr };
+#else
         const char * unmount_args[] = { "/bin/umount", "-a", "-r", nullptr };
+#endif
         run_process(unmount_args, loop, sub_buf);
     }
     catch (std::exception &e) {
@@ -650,7 +658,11 @@ static void unmount_disks(loop_t &loop, 
 static void swap_off(loop_t &loop, subproc_buffer &sub_buf)
 {
     try {
+#ifdef __NetBSD__
+        const char * swapoff_args[] = { "/sbin/swapctl", "-U", nullptr };
+#else
         const char * swapoff_args[] = { "/sbin/swapoff", "-a", nullptr };
+#endif
         run_process(swapoff_args, loop, sub_buf);
     }
     catch (std::exception &e) {
