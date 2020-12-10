$NetBSD: patch-zebra_kernel__socket.c,v 1.3 2020/12/10 17:08:17 kardel Exp $

	RTM_RESOLVE needs to be conditional

--- zebra/kernel_socket.c.orig	2017-10-03 14:57:10.000000000 +0000
+++ zebra/kernel_socket.c
@@ -208,7 +208,9 @@ const struct message rtm_type_str[] =
 #ifdef RTM_OLDDEL
   {RTM_OLDDEL,   "RTM_OLDDEL"},
 #endif /* RTM_OLDDEL */
+#ifdef RTM_RESOLVE
   {RTM_RESOLVE,  "RTM_RESOLVE"},
+#endif /* RTM_RESOLVE */
   {RTM_NEWADDR,  "RTM_NEWADDR"},
   {RTM_DELADDR,  "RTM_DELADDR"},
   {RTM_IFINFO,   "RTM_IFINFO"},
