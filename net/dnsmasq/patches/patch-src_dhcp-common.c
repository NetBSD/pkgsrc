$NetBSD: patch-src_dhcp-common.c,v 1.1 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/dhcp-common.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/dhcp-common.c
@@ -838,7 +838,7 @@ char *option_string(int prot, unsigned i
 		for (i = 0, j = 0; i < opt_len && j < buf_len ; i++)
 		  {
 		    char c = val[i];
-		    if (isprint((int)c))
+		    if (isprint((unsigned char)c))
 		      buf[j++] = c;
 		  }
 #ifdef HAVE_DHCP6
@@ -852,7 +852,7 @@ char *option_string(int prot, unsigned i
 		    for (k = i + 1; k < opt_len && k < l && j < buf_len ; k++)
 		     {
 		       char c = val[k];
-		       if (isprint((int)c))
+		       if (isprint((unsigned char)c))
 			 buf[j++] = c;
 		     }
 		    i = l;
@@ -873,7 +873,7 @@ char *option_string(int prot, unsigned i
 		    for (k = 0; k < len && j < buf_len; k++)
 		      {
 		       char c = *p++;
-		       if (isprint((int)c))
+		       if (isprint((unsigned char)c))
 			 buf[j++] = c;
 		     }
 		    i += len +2;
