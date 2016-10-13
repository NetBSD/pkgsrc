$NetBSD: patch-src_cmd-send.c,v 1.1 2016/10/13 11:03:13 fhajny Exp $

stdin is special.

--- src/cmd-send.c.orig	2016-04-25 16:50:45.000000000 +0000
+++ src/cmd-send.c
@@ -138,7 +138,7 @@ client_send (int argc, char *argv[])
     char *keyfn;
     char *priorities;
   } tls = {NULL, NULL, NULL, NULL};
-  int stdin = 0;
+  int rie_stdin = 0;
 
   event = riemann_event_new ();
 
@@ -263,7 +263,7 @@ client_send (int argc, char *argv[])
           break;
 
         case '0':
-          stdin = 1;
+          rie_stdin = 1;
           break;
 
         case '?':
@@ -312,7 +312,7 @@ client_send (int argc, char *argv[])
       goto end;
     }
 
-  if (stdin)
+  if (rie_stdin)
     {
       e = _send_continously (client_type, client, event);
 
