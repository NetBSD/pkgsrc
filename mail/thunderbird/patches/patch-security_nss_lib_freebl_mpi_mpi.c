$NetBSD: patch-security_nss_lib_freebl_mpi_mpi.c,v 1.3 2025/04/30 03:47:13 ryoon Exp $

Fix undefined behavior when calling <ctype.h> functions with illegal values.

security/nss/lib/freebl/mpi/mpi.c:4565:15: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
        xch = toupper(ch);

security/nss/lib/freebl/mpi/mpi.c:4611:14: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
        ch = tolower(ch);

https://bugzilla.mozilla.org/show_bug.cgi?id=1642081

--- security/nss/lib/freebl/mpi/mpi.c.orig	2025-03-18 04:01:12.000000000 +0000
+++ security/nss/lib/freebl/mpi/mpi.c
@@ -4917,7 +4917,7 @@ s_mp_tovalue(char ch, int r)
     int val, xch;
 
     if (r > 36)
-        xch = ch;
+        xch = (unsigned char) ch;
     else
         xch = toupper((unsigned char)ch);
 
