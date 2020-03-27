$NetBSD: patch-src_Util.cc,v 1.2 2020/03/27 20:52:19 joerg Exp $

SunOS needs strings.h for bzero().

--- src/Util.cc.orig	2007-06-06 09:21:19.000000000 +0000
+++ src/Util.cc
@@ -5,6 +5,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef __sun
+#include <strings.h>
+#endif
 #include <unistd.h>
 //#include <asm/types.h>
 #include <sys/ioctl.h>
@@ -89,7 +92,7 @@ Util::getRoute (const char* dest) {
   fscanf(fd, "%s", buff);
   pclose(fd);
 
-  log(INFO, "Source address = %s\n", buff);
+  mylog(INFO, "Source address = %s\n", buff);
 
   return strdup(buff);
 }
@@ -243,7 +246,7 @@ Util::write32 (uint8* data, int ofs, uin
 int
 Util::protocol2int (const char* protocol) {
   struct protoent* proto = getprotobyname(protocol);
-  log(DUMP, "p_proto = %d", proto->p_proto);
+  mylog(DUMP, "p_proto = %d", proto->p_proto);
   return proto->p_proto;
 }
 
@@ -278,12 +281,12 @@ Util::my_gethostbyname(char* host) {
    struct hostent* phost = gethostbyname(host);
    if (phost == NULL || phost->h_addrtype != AF_INET) {
      // Not a valid IP4 address
-     log(ERROR, "Invalid address");
+     mylog(ERROR, "Invalid address");
      return NULL;
    }
    struct in_addr *buff = (in_addr*)phost->h_addr_list[0];
    char* dst_addr = strdup(inet_ntoa(*buff));
-   log(DUMP, "dst_addr = %s", dst_addr);
+   mylog(DUMP, "dst_addr = %s", dst_addr);
    return dst_addr;
  }
 }
