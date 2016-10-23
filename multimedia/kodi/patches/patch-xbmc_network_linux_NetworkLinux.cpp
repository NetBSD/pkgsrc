$NetBSD: patch-xbmc_network_linux_NetworkLinux.cpp,v 1.3 2016/10/23 19:56:18 christos Exp $

We don't have RTF_LLINFO anymore, use getifaddrs()

--- xbmc/network/linux/NetworkLinux.cpp.orig	2015-10-19 02:31:15.000000000 -0400
+++ xbmc/network/linux/NetworkLinux.cpp	2016-10-23 15:49:24.032410793 -0400
@@ -48,7 +48,7 @@
   #include "network/osx/ioshacks.h"
 #endif
   #include <ifaddrs.h>
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #include <sys/sockio.h>
   #include <sys/wait.h>
   #include <net/if.h>
@@ -94,7 +94,7 @@
 
 bool CNetworkInterfaceLinux::IsWireless()
 {
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   return false;
 #else
   struct iwreq wrq;
@@ -218,7 +218,7 @@
   }
   if (result.empty())
     CLog::Log(LOGWARNING, "Unable to determine gateway");
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
    size_t needed;
    int mib[6];
    char *buf, *next, *lim;
@@ -248,7 +248,9 @@
    for (next = buf; next < lim; next += rtm->rtm_msglen) {
       rtm = (struct rt_msghdr *)next;
       sa = (struct sockaddr *)(rtm + 1);
+#if !defined(TARGET_NETBSD)
       sa = (struct sockaddr *)(SA_SIZE(sa) + (char *)sa);	
+#endif
       sockin = (struct sockaddr_in *)sa;
       if (inet_ntop(AF_INET, &sockin->sin_addr.s_addr,
          line, sizeof(line)) == NULL) {
@@ -359,7 +361,7 @@
 void CNetworkLinux::GetMacAddress(const std::string& interfaceName, char rawMac[6])
 {
   memset(rawMac, 0, 6);
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 
 #if !defined(IFT_ETHER)
 #define IFT_ETHER 0x6/* Ethernet CSMACD */
@@ -411,7 +413,7 @@
   char macAddrRaw[6];
   m_interfaces.clear();
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 
    // Query the list of interfaces.
    struct ifaddrs *list;
@@ -507,6 +509,16 @@
 
   if (!result.size())
        CLog::Log(LOGWARNING, "Unable to determine nameserver");
+#elif defined(TARGET_NETBSD)
+   struct __res_state state;
+   memset(&state, 0, sizeof(state));
+   res_ninit(&state);
+   
+   for (int i = 0; i < state.nscount; i ++)
+   {
+      std::string ns = inet_ntoa(((struct sockaddr_in *)&state.nsaddr_list[i])->sin_addr);
+      result.push_back(ns);
+   }
 #else
    res_init();
 
@@ -547,7 +559,7 @@
 
 #if defined (TARGET_DARWIN_IOS) // no timeout option available
   sprintf(cmd_line, "ping -c 1 %s", inet_ntoa(host_ip));
-#elif defined (TARGET_DARWIN) || defined (TARGET_FREEBSD)
+#elif defined (TARGET_DARWIN) || defined (TARGET_FREEBSD) || defined(TARGET_NETBSD)
   sprintf(cmd_line, "ping -c 1 -t %d %s", timeout_ms / 1000 + (timeout_ms % 1000) != 0, inet_ntoa(host_ip));
 #else
   sprintf(cmd_line, "ping -c 1 -w %d %s", timeout_ms / 1000 + (timeout_ms % 1000) != 0, inet_ntoa(host_ip));
@@ -618,6 +630,38 @@
   }
   return ret;
 }
+#elif defined(TARGET_NETBSD)
+#include <netdb.h>
+#include <ifaddrs.h>
+#include <cstring>
+
+bool CNetworkInterfaceLinux::GetHostMacAddress(unsigned long host_ip, std::string& mac)
+{
+	const char *iface = m_interfaceName.c_str();
+	struct ifaddrs *ifas, *ifa;
+	int r;
+	char buf[1024];
+
+	if (getifaddrs(&ifas) == -1) {
+		mac = strerror(errno);
+		return false;
+	}
+	for (ifa = ifas; ifa; ifa = ifa->ifa_next) {
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		if (strcmp(iface, ifa->ifa_name) != 0)
+			continue;
+		if ((r = getnameinfo(ifa->ifa_addr, ifa->ifa_addr->sa_len, buf,
+			sizeof(buf), NULL, 0, NI_NUMERICHOST)) != 0) {
+			mac = gai_strerror(r);
+			return false;
+		}
+		mac = buf;
+		break;
+	}
+	freeifaddrs(ifas);
+	return true;
+}
 #else
 bool CNetworkInterfaceLinux::GetHostMacAddress(unsigned long host_ip, std::string& mac)
 {
