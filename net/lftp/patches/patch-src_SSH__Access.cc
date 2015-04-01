$NetBSD: patch-src_SSH__Access.cc,v 1.1.2.2 2015/04/01 16:41:36 hiramatsu Exp $

Do not save fingerprints of unknown hosts.
--- src/SSH_Access.cc.orig	2015-03-21 19:58:58.000000000 +0000
+++ src/SSH_Access.cc
@@ -69,8 +69,8 @@ int SSH_Access::HandleSSHMessage()
       }
       if(s>=y_len && !strncasecmp(b+s-y_len,y,y_len))
       {
-	 pty_recv_buf->Put("yes\n");
-	 pty_send_buf->Put("yes\n");
+	 pty_recv_buf->Put("no\n");
+	 pty_send_buf->Put("no\n");
 	 return m;
       }
       if(!received_greeting && recv_buf->Size()>0)
