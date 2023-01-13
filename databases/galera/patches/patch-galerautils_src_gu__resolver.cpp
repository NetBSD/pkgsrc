$NetBSD: patch-galerautils_src_gu__resolver.cpp,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD support.
https://github.com/codership/galera/pull/632

--- galerautils/src/gu_resolver.cpp.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_resolver.cpp
@@ -17,7 +17,7 @@
 #include <map>
 #include <stdexcept>
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # include <ifaddrs.h>
 # define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
 # define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
@@ -79,7 +79,7 @@ private:
             family,
             socktype,
             protocol,
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 	    0, // FreeBSD gives ENOMEM error with non-zero value
 #else
             sizeof(struct sockaddr),
@@ -208,7 +208,7 @@ static unsigned int get_ifindex_by_addr(
 
     unsigned int idx(-1);
     int err(0);
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
     struct ifaddrs *if_addrs = NULL;
     struct ifaddrs *if_addr = NULL;
 
@@ -272,7 +272,7 @@ out:
                 }
 #if defined(__linux__) || defined(__GNU__)
                 idx = ifrp->ifr_ifindex;
-#elif defined(__sun__) || defined(__FreeBSD_kernel__)
+#elif defined(__sun__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
                 idx = ifrp->ifr_index;
 #else
 # error "Unsupported ifreq structure"
