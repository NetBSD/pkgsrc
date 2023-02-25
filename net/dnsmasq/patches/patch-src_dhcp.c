$NetBSD: patch-src_dhcp.c,v 1.1 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/dhcp.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/dhcp.c
@@ -916,14 +916,14 @@ void dhcp_read_ethers(void)
       
       lineno++;
       
-      while (strlen(buff) > 0 && isspace((int)buff[strlen(buff)-1]))
+      while (strlen(buff) > 0 && isspace((unsigned char)buff[strlen(buff)-1]))
 	buff[strlen(buff)-1] = 0;
       
       if ((*buff == '#') || (*buff == '+') || (*buff == 0))
 	continue;
       
-      for (ip = buff; *ip && !isspace((int)*ip); ip++);
-      for(; *ip && isspace((int)*ip); ip++)
+      for (ip = buff; *ip && !isspace((unsigned char)*ip); ip++);
+      for(; *ip && isspace((unsigned char)*ip); ip++)
 	*ip = 0;
       if (!*ip || parse_hex(buff, hwaddr, ETHER_ADDR_LEN, NULL, NULL) != ETHER_ADDR_LEN)
 	{
