$NetBSD: patch-attacher.c,v 1.1 2025/05/12 15:58:01 wiz Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- attacher.c.orig	2023-08-16 00:29:26.000000000 +0000
+++ attacher.c
@@ -73,7 +73,6 @@ extern int MasterPid, attach_fd;
 #ifdef MULTIUSER
 extern char *multi;
 extern int multiattach, multi_uid, own_uid;
-extern int tty_mode, tty_oldmode;
 # ifndef USE_SETEUID
 static int multipipe[2];
 # endif
@@ -160,9 +159,6 @@ int how;
 
       if (pipe(multipipe))
 	Panic(errno, "pipe");
-      if (chmod(attach_tty, 0666))
-	Panic(errno, "chmod %s", attach_tty);
-      tty_oldmode = tty_mode;
       eff_uid = -1;	/* make UserContext fork */
       real_uid = multi_uid;
       if ((ret = UserContext()) <= 0)
@@ -174,11 +170,6 @@ int how;
 	    Panic(errno, "UserContext");
 	  close(multipipe[1]);
 	  read(multipipe[0], &dummy, 1);
-	  if (tty_oldmode >= 0)
-	    {
-	      chmod(attach_tty, tty_oldmode);
-	      tty_oldmode = -1;
-	    }
 	  ret = UserStatus();
 #ifdef LOCK
 	  if (ret == SIG_LOCK)
@@ -224,9 +215,6 @@ int how;
       xseteuid(multi_uid);
       xseteuid(own_uid);
 #endif
-      if (chmod(attach_tty, 0666))
-	Panic(errno, "chmod %s", attach_tty);
-      tty_oldmode = tty_mode;
     }
 # endif /* USE_SETEUID */
 #endif /* MULTIUSER */
@@ -423,13 +411,6 @@ int how;
       ContinuePlease = 0;
 # ifndef USE_SETEUID
       close(multipipe[1]);
-# else
-      xseteuid(own_uid);
-      if (tty_oldmode >= 0)
-        if (chmod(attach_tty, tty_oldmode))
-          Panic(errno, "chmod %s", attach_tty);
-      tty_oldmode = -1;
-      xseteuid(real_uid);
 # endif
     }
 #endif
@@ -505,14 +486,6 @@ AttacherFinit SIGDEFARG
 	  close(s);
 	}
     }
-#ifdef MULTIUSER
-  if (tty_oldmode >= 0)
-    {
-      if (setuid(own_uid))
-        Panic(errno, "setuid");
-      chmod(attach_tty, tty_oldmode);
-    }
-#endif
   exit(0);
   SIGRETURN;
 }
