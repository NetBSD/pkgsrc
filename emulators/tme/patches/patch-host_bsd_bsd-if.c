$NetBSD: patch-host_bsd_bsd-if.c,v 1.1 2020/08/13 05:59:52 tsutsui Exp $

- handle the new (post-2007) way SIOCGIFCONF works. (PR/45921)
  XXX rewrite this to use getifaddrs()

--- host/bsd/bsd-if.c.orig	2003-10-16 02:48:23.000000000 +0000
+++ host/bsd/bsd-if.c
@@ -71,7 +71,8 @@ _TME_RCSID("$Id: bsd-if.c,v 1.3 2003/10/
 
 /* this macro helps us size a struct ifreq: */
 #ifdef HAVE_SOCKADDR_SA_LEN
-#define SIZEOF_IFREQ(ifr) (sizeof(ifr->ifr_name) + ifr->ifr_addr.sa_len)
+#define SIZEOF_IFREQ(ifr) \
+( sizeof(ifr->ifr_name) + (ifr->ifr_addr.sa_len > sizeof(ifr->ifr_ifru) ? ifr->ifr_addr.sa_len : sizeof(ifr->ifr_ifru)) )
 #else  /* !HAVE_SOCKADDR_SA_LEN */
 #define SIZEOF_IFREQ(ifr) (sizeof(ifr->ifr_name) + sizeof(struct sockaddr))
 #endif /* !HAVE_SOCKADDR_SA_LEN */
@@ -175,7 +176,7 @@ tme_bsd_if_find(const char *ifr_name_use
     if (ifr_user == NULL
 	&& (ifr_name_user != NULL
 	    ? !strncmp(ifr->ifr_name, ifr_name_user, sizeof(ifr->ifr_name))
-	    : !(ifr->ifr_flags & IFF_LOOPBACK))) {
+	    : !(saved_flags & IFF_LOOPBACK))) {
       ifr_user = ifr;
     }
   }
