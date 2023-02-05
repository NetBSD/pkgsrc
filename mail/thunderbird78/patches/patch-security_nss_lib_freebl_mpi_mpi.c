$NetBSD: patch-security_nss_lib_freebl_mpi_mpi.c,v 1.1 2023/02/05 08:32:24 he Exp $

--- security/nss/lib/freebl/mpi/mpi.c.orig	2020-08-28 21:33:15.000000000 +0000
+++ security/nss/lib/freebl/mpi/mpi.c
@@ -4661,9 +4661,9 @@ s_mp_tovalue(char ch, int r)
     int val, xch;
 
     if (r > 36)
-        xch = ch;
+        xch = (unsigned char) ch;
     else
-        xch = toupper(ch);
+        xch = toupper((unsigned char) ch);
 
     if (isdigit(xch))
         val = xch - '0';
@@ -4709,7 +4709,7 @@ s_mp_todigit(mp_digit val, int r, int lo
     ch = s_dmap_1[val];
 
     if (r <= 36 && low)
-        ch = tolower(ch);
+        ch = tolower((unsigned char) ch);
 
     return ch;
 
