$NetBSD: patch-xbmc_network_linux_NetworkLinux.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/network/linux/NetworkLinux.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/network/linux/NetworkLinux.cpp
@@ -48,7 +48,7 @@
   #include "network/osx/ioshacks.h"
 #endif
   #include <ifaddrs.h>
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #include <sys/sockio.h>
   #include <sys/wait.h>
   #include <net/if.h>
@@ -94,7 +94,7 @@ std::string& CNetworkInterfaceLinux::Get
 
 bool CNetworkInterfaceLinux::IsWireless()
 {
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   return false;
 #else
   struct iwreq wrq;
@@ -218,7 +218,7 @@ std::string CNetworkInterfaceLinux::GetC
   }
   if (result.empty())
     CLog::Log(LOGWARNING, "Unable to determine gateway");
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
    size_t needed;
    int mib[6];
    char *buf, *next, *lim;
@@ -248,7 +248,9 @@ std::string CNetworkInterfaceLinux::GetC
    for (next = buf; next < lim; next += rtm->rtm_msglen) {
       rtm = (struct rt_msghdr *)next;
       sa = (struct sockaddr *)(rtm + 1);
+#if !defined(TARGET_NETBSD)
       sa = (struct sockaddr *)(SA_SIZE(sa) + (char *)sa);	
+#endif
       sockin = (struct sockaddr_in *)sa;
       if (inet_ntop(AF_INET, &sockin->sin_addr.s_addr,
          line, sizeof(line)) == NULL) {
@@ -359,7 +361,7 @@ CNetworkInterface* CNetworkLinux::GetFir
 void CNetworkLinux::GetMacAddress(const std::string& interfaceName, char rawMac[6])
 {
   memset(rawMac, 0, 6);
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 
 #if !defined(IFT_ETHER)
 #define IFT_ETHER 0x6/* Ethernet CSMACD */
@@ -411,7 +413,7 @@ void CNetworkLinux::queryInterfaceList()
   char macAddrRaw[6];
   m_interfaces.clear();
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 
    // Query the list of interfaces.
    struct ifaddrs *list;
@@ -547,7 +549,7 @@ bool CNetworkLinux::PingHost(unsigned lo
 
 #if defined (TARGET_DARWIN_IOS) // no timeout option available
   sprintf(cmd_line, "ping -c 1 %s", inet_ntoa(host_ip));
-#elif defined (TARGET_DARWIN) || defined (TARGET_FREEBSD)
+#elif defined (TARGET_DARWIN) || defined (TARGET_FREEBSD) || defined(TARGET_NETBSD)
   sprintf(cmd_line, "ping -c 1 -t %d %s", timeout_ms / 1000 + (timeout_ms % 1000) != 0, inet_ntoa(host_ip));
 #else
   sprintf(cmd_line, "ping -c 1 -w %d %s", timeout_ms / 1000 + (timeout_ms % 1000) != 0, inet_ntoa(host_ip));
@@ -568,7 +570,7 @@ bool CNetworkLinux::PingHost(unsigned lo
   return result == 0;
 }
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 bool CNetworkInterfaceLinux::GetHostMacAddress(unsigned long host_ip, std::string& mac)
 {
   bool ret = false;
