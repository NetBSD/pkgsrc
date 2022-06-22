$NetBSD: patch-servers_slapd_daemon.c,v 1.1 2022/06/22 13:32:49 taca Exp $

Apply fix from openldap's gitlab <ced6652e>:
ITS#9847 slapd: fix kqueue for FreeBSD/MacOSX/OpenBSD

--- servers/slapd/daemon.c.orig	2022-05-04 14:55:23.000000000 +0000
+++ servers/slapd/daemon.c
@@ -227,11 +227,10 @@ static slap_daemon_st *slap_daemon;
     slap_daemon[t].sd_kq = kqueue(); \
 } while (0)
 
-/* a kqueue fd obtained before a fork can't be used in child process.
- * close it and reacquire it.
+/* a kqueue fd obtained before a fork isn't inherited by child process.
+ * reacquire it.
  */
 # define SLAP_SOCK_INIT2() do { \
-	close(slap_daemon[0].sd_kq); \
 	slap_daemon[0].sd_kq = kqueue(); \
 } while (0)
 
