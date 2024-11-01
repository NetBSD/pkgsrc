$NetBSD: patch-dlls_nsiproxy.sys_ip.c,v 1.1 2024/11/01 14:10:47 triaxx Exp $

RTF_LLINFO has been removed (https://mail-index.netbsd.org/tech-net/2016/04/12/msg005766.html).
RTF_MULTICAST is not implemented.

--- dlls/nsiproxy.sys/ip.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/nsiproxy.sys/ip.c
@@ -1133,7 +1133,11 @@ static NTSTATUS ipv4_neighbour_enumerate
     }
 #elif defined(HAVE_SYS_SYSCTL_H)
     {
+#ifdef RTF_LLINFO
         int mib[] = { CTL_NET, PF_ROUTE, 0, AF_INET, NET_RT_FLAGS, RTF_LLINFO }, sinarp_len;
+#else
+        int mib[] = { CTL_NET, PF_ROUTE, 0, AF_INET, NET_RT_FLAGS, 0 }, sinarp_len;
+#endif
         size_t needed;
         char *buf = NULL, *lim, *next;
         struct rt_msghdr *rtm;
@@ -1390,7 +1394,9 @@ static NTSTATUS ipv4_forward_enumerate_a
             }
 
             /* Ignore gateway routes which are multicast */
+#ifdef RTF_MULTICAST
             if ((rtm->rtm_flags & RTF_GATEWAY) && (rtm->rtm_flags & RTF_MULTICAST)) continue;
+#endif
 
             entry.if_index = rtm->rtm_index;
             if (!convert_index_to_luid( entry.if_index, &entry.luid )) continue;
