$NetBSD: patch-Library_System_Socket_socket__support__unix.c,v 1.1 2014/06/28 23:10:39 dholland Exp $

Silence warnings about pointer casts.

--- Library/System/Socket/socket_support_unix.c~	2007-07-01 03:53:35.000000000 +0000
+++ Library/System/Socket/socket_support_unix.c
@@ -110,7 +110,7 @@ int make_initiating_socket_unix(char *se
      current server socket */
 
   old_int_handler = signal(SIGINT, unlink_server_and_exit); 
-  if ((int)old_int_handler == -1)
+  if ((intptr_t)old_int_handler == -1)
     {
       socket_warn_errno("attempt to redirect SIGINT signal");
       close(server_id);
@@ -119,7 +119,7 @@ int make_initiating_socket_unix(char *se
     }
 
   old_term_handler = signal(SIGTERM, unlink_server_and_exit);
-  if ((int)old_term_handler == -1)
+  if ((intptr_t)old_term_handler == -1)
     {
       socket_warn_errno("attempt to redirect SIGTERM signal");
       close(server_id);
@@ -160,7 +160,7 @@ int make_initiating_socket_unix(char *se
   /* re-install old handlers */
 
   old_int_handler = signal(SIGINT, old_int_handler);
-  if ((int)old_int_handler == -1)
+  if ((intptr_t)old_int_handler == -1)
     {
       socket_warn_errno("attempt to restore original SIGINT handler");
       close(server_id);
@@ -170,7 +170,7 @@ int make_initiating_socket_unix(char *se
     }
 
   old_term_handler = signal(SIGTERM, old_term_handler);
-  if ((int)old_term_handler == -1)
+  if ((intptr_t)old_term_handler == -1)
     {
       socket_warn_errno("attempt to restore original SIGTERM handler");
       close(server_id);
@@ -686,16 +686,16 @@ int min_port_num(void) 
  */
 void ignore_broken_pipe_signals(void)
 {
-  int status;
-  status = (int)signal(SIGPIPE, SIG_IGN);
-  /* printf("*** First time, old SIGPIPE handler was %d\n",status); */
+  long status;
+  status = (long)(intptr_t)signal(SIGPIPE, SIG_IGN);
+  /* printf("*** First time, old SIGPIPE handler was %ld\n",status); */
   if (status < 0)
     {
       socket_warn_errno("setting up ignoring of SIGPIPE signals (will \
 ignore error)");
     }
-  /* status = (int)signal(SIGPIPE, SIG_IGN); */
-  /* printf("*** Second time, old SIGPIPE handler was %d\n",status); */
+  /* status = (long)(intptr_t)signal(SIGPIPE, SIG_IGN); */
+  /* printf("*** Second time, old SIGPIPE handler was %ld\n",status); */
 }
 
 /***********************************************************************/
