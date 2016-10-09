$NetBSD: patch-lib_nicInfo_nicInfoPosix.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/nicInfo/nicInfoPosix.c.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/nicInfo/nicInfoPosix.c
@@ -62,6 +62,8 @@
 #   include <net/if.h>
 #endif
 
+__thread struct __res_state myres;
+
 /*
  * resolver(3) and IPv6:
  *
@@ -471,7 +473,7 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
    char namebuf[DNSINFO_MAX_ADDRLEN + 1];
    char **s;
 
-   if (res_init() == -1) {
+   if (res_ninit(&myres) == -1) {
       return FALSE;
    }
 
@@ -492,7 +494,7 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
     */
    dnsConfigInfo->domainName =
       Util_SafeCalloc(1, sizeof *dnsConfigInfo->domainName);
-   *dnsConfigInfo->domainName = Util_SafeStrdup(_res.defdname);
+   *dnsConfigInfo->domainName = Util_SafeStrdup(myres.defdname);
 
    /*
     * Name servers.
@@ -502,7 +504,7 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
    /*
     * Search suffixes.
     */
-   for (s = _res.dnsrch; *s; s++) {
+   for (s = myres.dnsrch; *s; s++) {
       DnsHostname *suffix;
 
       /* Check to see if we're going above our limit. See bug 605821. */
@@ -550,12 +552,12 @@ RecordResolverNS(DnsConfigInfo *dnsConfi
 #if defined RESOLVER_IPV6_GETSERVERS
    {
       union res_sockaddr_union *ns;
-      ns = Util_SafeCalloc(_res.nscount, sizeof *ns);
-      if (res_getservers(&_res, ns, _res.nscount) != _res.nscount) {
+      ns = Util_SafeCalloc(myres.nscount, sizeof *ns);
+      if (res_getservers(&myres, ns, myres.nscount) != myres.nscount) {
          g_warning("%s: res_getservers failed.\n", __func__);
          return;
       }
-      for (i = 0; i < _res.nscount; i++) {
+      for (i = 0; i < myres.nscount; i++) {
          struct sockaddr *sa = (struct sockaddr *)&ns[i];
          if (sa->sa_family == AF_INET || sa->sa_family == AF_INET6) {
             TypedIpAddress *ip;
@@ -579,7 +581,7 @@ RecordResolverNS(DnsConfigInfo *dnsConfi
        * Name servers (IPv4).
        */
       for (i = 0; i < MAXNS; i++) {
-         struct sockaddr_in *sin = &_res.nsaddr_list[i];
+         struct sockaddr_in *sin = &myres.nsaddr_list[i];
          if (sin->sin_family == AF_INET) {
             TypedIpAddress *ip;
 
@@ -600,7 +602,7 @@ RecordResolverNS(DnsConfigInfo *dnsConfi
        * Name servers (IPv6).
        */
       for (i = 0; i < MAXNS; i++) {
-         struct sockaddr_in6 *sin6 = _res._u._ext.nsaddrs[i];
+         struct sockaddr_in6 *sin6 = myres._u._ext.nsaddrs[i];
          if (sin6) {
             TypedIpAddress *ip;
 
