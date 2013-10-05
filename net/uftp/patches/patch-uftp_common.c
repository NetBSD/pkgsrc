$NetBSD: patch-uftp_common.c,v 1.1 2013/10/05 17:40:38 mspo Exp $
netbsd does not have SIOCGIFINDEX

--- uftp_common.c-orig	2013-10-05 01:33:19.000000000 +0000
+++ uftp_common.c
@@ -141,11 +141,13 @@ void getiflist(struct iflist *list, int 
     while (ifa_tmp && (*len < count)) {
         strncpy(ifr_tmp.ifr_name, ifa_tmp->ifa_name, sizeof(ifr_tmp.ifr_name));
         ifr_tmp.ifr_name[sizeof(ifr_tmp.ifr_name)-1] = '\x0';
+#ifndef NOSIOCGIFINDEX        
         if (ioctl(s, SIOCGIFINDEX, &ifr_tmp) == -1) {
             syserror(0, 0, "Error getting interface index for interface %s",
                      ifa_tmp->ifa_name);
             continue;
         }
+#endif        
         if (ifa_tmp->ifa_addr && ((ifa_tmp->ifa_addr->sa_family == AF_INET) ||
                                   (ifa_tmp->ifa_addr->sa_family == AF_INET6)) &&
                     ((ifa_tmp->ifa_flags & IFF_UP) != 0)) {
@@ -156,11 +158,14 @@ void getiflist(struct iflist *list, int 
                     sizeof(struct sockaddr_storage));
             list[*len].isloopback = (ifa_tmp->ifa_flags & IFF_LOOPBACK) != 0;
             list[*len].ismulti = (ifa_tmp->ifa_flags & IFF_MULTICAST) != 0;
+#ifndef NOSIOCGIFINDEX        
+        if (ioctl(s, SIOCGIFINDEX, &ifr_tmp) == -1) {
 #ifdef ifr_ifindex
             list[*len].ifidx = ifr_tmp.ifr_ifindex;
 #else
             list[*len].ifidx = ifr_tmp.ifr_index;
 #endif
+#endif
 
             (*len)++;
         }
