$NetBSD: patch-lib_inets_test_inets__socketwrap__SUITE__data_setuid__socket__wrap.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- lib/inets/test/inets_socketwrap_SUITE_data/setuid_socket_wrap.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ lib/inets/test/inets_socketwrap_SUITE_data/setuid_socket_wrap.c
@@ -66,7 +66,7 @@ int parse_addr(addr, str)
     if ((cp = strrchr(str, (int)':')) != NULL)
         *cp++ = '\0';
     if (cp) {
-        if (!isdigit((int)cp[0])) {
+        if (!isdigit((unsigned char)cp[0])) {
             if ((se = getservbyname(cp, "tcp")) != NULL) {
                 port = ntohs(se->s_port);
 	    } else {
