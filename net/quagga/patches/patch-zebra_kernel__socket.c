$NetBSD: patch-zebra_kernel__socket.c,v 1.1 2016/06/19 23:05:51 joerg Exp $

--- zebra/kernel_socket.c.orig	2016-06-19 18:59:02.266180373 +0000
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
@@ -242,7 +244,9 @@ static const struct message rtm_flag_str
 #ifdef RTF_CLONING
   {RTF_CLONING,   "CLONING"},
 #endif /* RTF_CLONING */
+#ifdef RTF_XRESOLVE
   {RTF_XRESOLVE,  "XRESOLVE"},
+#endif /* RTF_XRESOLVE */
 #ifdef RTF_LLINFO
   {RTF_LLINFO,    "LLINFO"},
 #endif /* RTF_LLINFO */
