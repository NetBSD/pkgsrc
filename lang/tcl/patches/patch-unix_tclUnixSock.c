$NetBSD: patch-unix_tclUnixSock.c,v 1.1.2.2 2017/10/04 16:07:20 spz Exp $

* Move pragmas to make gcc happy;
  http://core.tcl.tk/tcl/vinfo/dce77b1b201e9329

--- unix/tclUnixSock.c.orig	2017-04-28 18:05:52.000000000 +0000
+++ unix/tclUnixSock.c
@@ -700,6 +700,8 @@ TcpClose2Proc(
  */
 
 #ifndef NEED_FAKE_RFC2553
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wstrict-aliasing"
 static inline int
 IPv6AddressNeedsNumericRendering(
     struct in6_addr addr)
@@ -713,16 +715,14 @@ IPv6AddressNeedsNumericRendering(
      * at least some versions of OSX.
      */
 
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wstrict-aliasing"
     if (!IN6_IS_ADDR_V4MAPPED(&addr)) {
-#pragma GCC diagnostic pop
         return 0;
     }
 
     return (addr.s6_addr[12] == 0 && addr.s6_addr[13] == 0
             && addr.s6_addr[14] == 0 && addr.s6_addr[15] == 0);
 }
+#pragma GCC diagnostic pop
 #endif /* NEED_FAKE_RFC2553 */
 
 static void
