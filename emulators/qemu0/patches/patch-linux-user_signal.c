$NetBSD: patch-linux-user_signal.c,v 1.2 2016/10/04 13:31:09 kamil Exp $

struct siginfo is unrecognized on CentOS Linux 7. Backport solution from
recent qemu releases: "struct siginfo" -> "siginfo_t".

--- linux-user/signal.c.orig	2011-10-12 16:41:43.000000000 +0000
+++ linux-user/signal.c
@@ -3243,7 +3243,7 @@ struct target_signal_frame {
 };
 
 struct rt_signal_frame {
-    struct siginfo info;
+    siginfo_t info;
     struct ucontext uc;
     uint32_t tramp[2];
 };
@@ -3461,9 +3461,9 @@ struct target_signal_frame {
 };
 
 struct rt_signal_frame {
-        struct siginfo *pinfo;
+        siginfo_t *pinfo;
         void *puc;
-        struct siginfo info;
+        siginfo_t info;
         struct ucontext uc;
         uint8_t retcode[8];       /* Trampoline code. */
 };
