$NetBSD: patch-socket.c,v 1.2 2025/05/12 15:58:01 wiz Exp $

Include <uio.h> for iovec. 

Also:
https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- socket.c.orig	2023-08-16 00:29:26.000000000 +0000
+++ socket.c
@@ -34,9 +34,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 # include <sys/socket.h>
-# ifdef _OpenBSD_
-#  include <sys/uio.h>
-# endif
+# include <sys/uio.h>
 # include <sys/un.h>
 
 #ifndef SIGINT
@@ -169,8 +167,13 @@ bool *is_sock;
   xsetegid(real_gid);
 #endif
 
-  if ((dirp = opendir(SockPath)) == 0)
-    Panic(errno, "Cannot opendir %s", SockPath);
+  if ((dirp = opendir(SockPath)) == 0) {
+    if (eff_uid == real_uid) {
+      Panic(errno, "Cannot opendir %s", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
 
   slist = 0;
   slisttail = &slist;
@@ -826,6 +829,11 @@ int pid;
   return UserStatus();
 }
 
+static void KillUnpriv(pid_t pid, int sig) {
+    UserContext();
+    UserReturn(kill(pid, sig));
+}
+
 #ifdef hpux
 /*
  * From: "F. K. Bruner" <napalm@ugcs.caltech.edu>
@@ -911,14 +919,14 @@ struct win *wi;
             {
 	      Msg(errno, "Could not perform necessary sanity checks on pts device.");
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      return -1;
             }
           if (strcmp(ttyname_in_ns, m->m_tty))
             {
 	      Msg(errno, "Attach: passed fd does not match tty: %s - %s!", ttyname_in_ns, m->m_tty[0] != '\0' ? m->m_tty : "(null)");
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      return -1;
 	    }
 	  /* m->m_tty so far contains the actual name of the pts device in the
@@ -935,19 +943,19 @@ struct win *wi;
 	{
 	  Msg(errno, "Attach: passed fd does not match tty: %s - %s!", m->m_tty, myttyname ? myttyname : "NULL");
 	  close(i);
-	  Kill(pid, SIG_BYE);
+	  KillUnpriv(pid, SIG_BYE);
 	  return -1;
 	}
     }
   else if ((i = secopen(m->m_tty, O_RDWR | O_NONBLOCK, 0)) < 0)
     {
       Msg(errno, "Attach: Could not open %s!", m->m_tty);
-      Kill(pid, SIG_BYE);
+      KillUnpriv(pid, SIG_BYE);
       return -1;
     }
 #ifdef MULTIUSER
   if (attach)
-    Kill(pid, SIGCONT);
+    KillUnpriv(pid, SIGCONT);
 #endif
 
 #if defined(ultrix) || defined(pyr) || defined(NeXT)
@@ -960,7 +968,7 @@ struct win *wi;
 	{
 	  write(i, "Attaching from inside of screen?\n", 33);
 	  close(i);
-	  Kill(pid, SIG_BYE);
+	  KillUnpriv(pid, SIG_BYE);
 	  Msg(0, "Attach msg ignored: coming from inside.");
 	  return -1;
 	}
@@ -971,7 +979,7 @@ struct win *wi;
 	  {
 	      write(i, "Access to session denied.\n", 26);
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      Msg(0, "Attach: access denied for user %s.", user);
 	      return -1;
 	  }
@@ -1289,7 +1297,7 @@ ReceiveMsg()
             Msg(0, "Query attempt with bad pid(%d)!", m.m.command.apid);
           }
           else {
-            Kill(m.m.command.apid,
+            KillUnpriv(m.m.command.apid,
                (queryflag >= 0)
                    ? SIGCONT
                    : SIG_BYE); /* Send SIG_BYE if an error happened */
