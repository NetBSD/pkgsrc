$NetBSD: patch-socket.c,v 1.7 2025/05/12 16:03:20 wiz Exp $

Include <uio.h> for iovec.

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- socket.c.orig	2024-08-28 19:55:03.000000000 +0000
+++ socket.c
@@ -35,9 +35,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/socket.h>
-#ifdef _OpenBSD_
 #include <sys/uio.h>
-#endif
 #include <sys/un.h>
 #include <utime.h>
 #include <stdint.h>
@@ -91,6 +89,11 @@ static void AskPassword(Message *);
 static bool CheckPassword(const char *password);
 static void PasswordProcessInput(char *, size_t);
 
+static void KillUnpriv(pid_t pid, int sig) {
+	UserContext();
+	UserReturn(kill(pid, sig));
+}
+
 #define SOCKMODE (S_IWRITE | S_IREAD | (displays ? S_IEXEC : 0) | (multi ? 1 : 0))
 
 /*
@@ -148,8 +151,13 @@ int FindSocket(int *fdp, int *nfoundp, i
 	xseteuid(real_uid);
 	xsetegid(real_gid);
 
-	if ((dirp = opendir(SocketPath)) == NULL)
-		Panic(errno, "Cannot opendir %s", SocketPath);
+	if ((dirp = opendir(SocketPath)) == NULL) {
+		if (eff_uid == real_uid) {
+			Panic(errno, "Cannot opendir %s", SocketPath);
+		} else {
+			Panic(0, "Error accessing %s", SocketPath);
+		}
+	}
 
 	slist = NULL;
 	slisttail = &slist;
@@ -606,7 +614,7 @@ static int CreateTempDisplay(Message *m,
 				Msg(errno, "Could not perform necessary sanity "
 					   "checks on pts device.");
 				close(i);
-				Kill(pid, SIG_BYE);
+				KillUnpriv(pid, SIG_BYE);
 				return -1;
 			}
 			if (strcmp(ttyname_in_ns, m->m_tty)) {
@@ -615,7 +623,7 @@ static int CreateTempDisplay(Message *m,
 				    ttyname_in_ns,
 				    m->m_tty[0] != '\0' ? m->m_tty : "(null)");
 				close(i);
-				Kill(pid, SIG_BYE);
+				KillUnpriv(pid, SIG_BYE);
 				return -1;
 			}
 			/* m->m_tty so far contains the actual name of the pts
@@ -633,24 +641,24 @@ static int CreateTempDisplay(Message *m,
 			    "Attach: passed fd does not match tty: %s - %s!",
 			    m->m_tty, myttyname ? myttyname : "NULL");
 			close(i);
-			Kill(pid, SIG_BYE);
+			KillUnpriv(pid, SIG_BYE);
 			return -1;
 		}
 	} else if ((i = secopen(m->m_tty, O_RDWR | O_NONBLOCK, 0)) < 0) {
 		Msg(errno, "Attach: Could not open %s!", m->m_tty);
-		Kill(pid, SIG_BYE);
+		KillUnpriv(pid, SIG_BYE);
 		return -1;
 	}
 
 	if (attach)
-		Kill(pid, SIGCONT);
+		KillUnpriv(pid, SIGCONT);
 
 	if (attach) {
 		if (display || win) {
 			int unused_result = write(i, "Attaching from inside of screen?\n", 33);
 			(void)unused_result; /* unused */
 			close(i);
-			Kill(pid, SIG_BYE);
+			KillUnpriv(pid, SIG_BYE);
 			Msg(0, "Attach msg ignored: coming from inside.");
 			return -1;
 		}
@@ -673,7 +681,7 @@ static int CreateTempDisplay(Message *m,
 		(void)unused_result; /* unused */
 		close(i);
 		Msg(0, "Attach: could not make display for user %s", user);
-		Kill(pid, SIG_BYE);
+		KillUnpriv(pid, SIG_BYE);
 		return -1;
 	}
 	if (attach) {
@@ -879,7 +887,7 @@ void ReceiveMsg(void)
 				Msg(0, "Query attempt with bad pid(%d)!", m.m.command.apid);
 			}
 			else {
-				Kill(m.m.command.apid, (queryflag >= 0) ? SIGCONT : SIG_BYE);	/* Send SIG_BYE if an error happened */
+				KillUnpriv(m.m.command.apid, (queryflag >= 0) ? SIGCONT : SIG_BYE);	/* Send SIG_BYE if an error happened */
 				queryflag = -1;
 			}
 		}
