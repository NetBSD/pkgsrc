$NetBSD: patch-src_util_grb__net.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/grb_net.cc.orig	2026-06-25 08:03:37.070727737 +0000
+++ src/util/grb_net.cc
@@ -68,9 +68,9 @@ static int sockAddrCmpAddr(const struct sockaddr* sa, 
 
     if (sa->sa_family == AF_INET6) {
         if (prefix > 0 && prefix < 129) {
-            return std::memcmp((SOCK_ADDR_IN6_ADDR(sa)).s6_addr, (SOCK_ADDR_IN6_ADDR(sb).s6_addr), sizeof(SOCK_ADDR_IN6_ADDR(sa).s6_addr[0]) * prefix / 8);
+            return memcmp((SOCK_ADDR_IN6_ADDR(sa)).s6_addr, (SOCK_ADDR_IN6_ADDR(sb).s6_addr), sizeof(SOCK_ADDR_IN6_ADDR(sa).s6_addr[0]) * prefix / 8);
         }
-        return std::memcmp(&(SOCK_ADDR_IN6_ADDR(sa)), &(SOCK_ADDR_IN6_ADDR(sb)), sizeof(SOCK_ADDR_IN6_ADDR(sa)));
+        return memcmp(&(SOCK_ADDR_IN6_ADDR(sa)), &(SOCK_ADDR_IN6_ADDR(sb)), sizeof(SOCK_ADDR_IN6_ADDR(sa)));
     }
 
     throw_std_runtime_error("Unsupported address family: {}", sa->sa_family);
@@ -155,14 +155,14 @@ std::string GrbNet::getHostName()
     int len = addr->sa_family == AF_INET6 ? sizeof(struct sockaddr_in6) : sizeof(struct sockaddr_in);
     int ret = getnameinfo(addr, len, hoststr, sizeof(hoststr), portstr, sizeof(portstr), NI_NOFQDN);
     if (ret != 0) {
-        log_warning("Could not determine getnameinfo: {}", std::strerror(errno));
+        log_warning("Could not determine getnameinfo: {}", strerror(errno));
         hoststr[0] = '\0';
     }
     hostName = hoststr;
     if (hostName.empty()) {
         ret = getnameinfo(addr, len, hoststr, sizeof(hoststr), portstr, sizeof(portstr), NI_NUMERICHOST);
         if (ret != 0) {
-            log_warning("Could not determine getnameinfo: {}", std::strerror(errno));
+            log_warning("Could not determine getnameinfo: {}", strerror(errno));
             hoststr[0] = '\0';
             return hostName;
         }
@@ -200,7 +200,7 @@ std::string GrbNet::ipToInterface(const std::string& i
     char host[NI_MAXHOST] = "";
 
     if (getifaddrs(&ifaddr) == -1) {
-        log_error("Could not getifaddrs: {}", std::strerror(errno));
+        log_error("Could not getifaddrs: {}", strerror(errno));
     }
 
     for (auto ifa = ifaddr; ifa; ifa = ifa->ifa_next) {
