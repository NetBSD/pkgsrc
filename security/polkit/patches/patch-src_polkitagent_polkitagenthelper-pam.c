$NetBSD: patch-src_polkitagent_polkitagenthelper-pam.c,v 1.1 2025/12/21 15:44:05 wiz Exp $

Fix build on NetBSD.
https://github.com/polkit-org/polkit/pull/624

--- src/polkitagent/polkitagenthelper-pam.c.orig	2025-12-21 14:47:56.694667615 +0000
+++ src/polkitagent/polkitagenthelper-pam.c
@@ -141,7 +141,9 @@ main (int argc, char *argv[])
   if (argv[1] != NULL && strcmp (argv[1], "--socket-activated") == 0)
     {
       socklen_t socklen = sizeof(int);
+#ifdef SO_PEERCRED
       struct ucred ucred;
+#endif
 
       user_to_auth_free = read_cookie (argc, argv);
       if (!user_to_auth_free)
@@ -165,8 +167,12 @@ main (int argc, char *argv[])
           goto error;
         }
 
+#ifdef SO_PEERCRED
       socklen = sizeof(ucred);
       rc = getsockopt(STDIN_FILENO, SOL_SOCKET, SO_PEERCRED, &ucred, &socklen);
+#else
+      rc = -1;
+#endif
       if (rc < 0)
         {
           syslog (LOG_ERR, "Unable to get credentials from socket");
@@ -174,7 +180,9 @@ main (int argc, char *argv[])
           goto error;
         }
 
+#ifdef SO_PEERCRED
       uid = ucred.uid;
+#endif
     }
   else
     user_to_auth = argv[1];
