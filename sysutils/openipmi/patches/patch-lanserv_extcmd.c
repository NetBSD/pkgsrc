$NetBSD: patch-lanserv_extcmd.c,v 1.1 2020/11/03 20:55:34 otis Exp $

Create compat functions.

--- lanserv/extcmd.c.orig	2017-07-27 22:01:19.000000000 +0000
+++ lanserv/extcmd.c
@@ -53,6 +53,7 @@
  *      written permission.
  */
 #include <config.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -61,8 +62,13 @@
 #elif defined(HAVE_SYS_ETHERNET_H)
 #include <sys/ethernet.h>
 #else
+#if defined (__NetBSD__)
+#include <net/if.h>
+#include <net/if_ether.h>
+#else
 #error "either netinet/ether.h or sys/ethernet.h must exist."
 #endif
+#endif
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>
@@ -73,6 +79,53 @@
 #include <OpenIPMI/serv.h>
 #include <OpenIPMI/extcmd.h>
 
+/*
+ * These two functions (ether_aton_r() and ether_ntoa_r()
+ * were obtained from FreeBSD and modified for NetBSD
+ */
+
+#ifndef ether_aton_r
+/*
+ * Convert an ASCII representation of an ethernet address to binary form.
+ */
+struct ether_addr *
+ether_aton_r(const char *a, struct ether_addr *e)
+{
+        int i;
+        unsigned int o0, o1, o2, o3, o4, o5;
+
+        i = sscanf(a, "%x:%x:%x:%x:%x:%x", &o0, &o1, &o2, &o3, &o4, &o5);
+        if (i != 6)
+                return (NULL);
+        e->ether_addr_octet[0]=o0;
+        e->ether_addr_octet[1]=o1;
+        e->ether_addr_octet[2]=o2;
+        e->ether_addr_octet[3]=o3;
+        e->ether_addr_octet[4]=o4;
+        e->ether_addr_octet[5]=o5;
+        return (e);
+}
+#endif
+
+#ifndef ether_ntoa_r
+/*
+ * Convert a binary representation of an ethernet address to an ASCII string.
+ */
+char *
+ether_ntoa_r(const struct ether_addr *n, char *a)
+{
+        int i;
+
+        i = sprintf(a, "%02x:%02x:%02x:%02x:%02x:%02x", n->ether_addr_octet[0],
+            n->ether_addr_octet[1], n->ether_addr_octet[2],
+	    n->ether_addr_octet[3], n->ether_addr_octet[4],
+	    n->ether_addr_octet[5]);
+        if (i < 17)
+                return (NULL);
+        return (a);
+}
+#endif
+
 static int
 extcmd_getval(void *baseloc, extcmd_info_t *t, char *val)
 {
