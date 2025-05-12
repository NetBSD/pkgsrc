$NetBSD: patch-screen.c,v 1.7 2025/05/12 16:03:20 wiz Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- screen.c.orig	2024-08-28 19:55:03.000000000 +0000
+++ screen.c
@@ -145,8 +145,6 @@ bool      hastruecolor = false;
 
 char     *multi;
 int       multiattach;
-int       tty_mode;
-int       tty_oldmode = -1;
 
 char      HostName[MAXSTR];
 pid_t     MasterPid;
@@ -199,6 +197,21 @@ static int GotSigChld;
 /********************************************************************/
 /********************************************************************/
 
+static int lf_secreopen(char *name, int wantfd, struct Log *l)
+{
+	int got_fd;
+
+	close(wantfd);
+	if (((got_fd = secopen(name, O_WRONLY | O_CREAT | O_APPEND, 0666)) < 0) || lf_move_fd(got_fd, wantfd) < 0) {
+		logfclose(l);
+		return -1;
+	}
+	l->st->st_ino = l->st->st_dev = 0;
+	return 0;
+}
+
+
+
 static struct passwd *getpwbyname(char *name, struct passwd *ppp)
 {
 	int n;
@@ -349,6 +362,10 @@ int main(int argc, char **argv)
 #ifdef ENABLE_TELNET
 	af                = AF_UNSPEC;
 #endif
+	/* lf_secreopen() is vital for the secure operation in setuid-root context.
+	 * Do not remove it
+	 */
+	logreopen_register(lf_secreopen);
 
 	real_uid          = getuid();
 	real_gid          = getgid();
@@ -747,7 +764,6 @@ int main(int argc, char **argv)
 
 		/* ttyname implies isatty */
 		SetTtyname(true, &st);
-		tty_mode = (int)st.st_mode & 0777;
 
 		fl = fcntl(0, F_GETFL, 0);
 		if (fl != -1 && (fl & (O_RDWR | O_RDONLY | O_WRONLY)) == O_RDWR)
@@ -846,22 +862,47 @@ int main(int argc, char **argv)
 #endif
 	}
 
-	if (stat(SocketPath, &st) == -1)
-		Panic(errno, "Cannot access %s", SocketPath);
-	else if (!S_ISDIR(st.st_mode))
-		Panic(0, "%s is not a directory.", SocketPath);
+	if (stat(SocketPath, &st) == -1) {
+		if (eff_uid == real_uid) {
+			Panic(errno, "Cannot access %s", SocketPath);
+		} else {
+			Panic(0, "Error accessing %s", SocketPath);
+		}
+	}
+	else if (!S_ISDIR(st.st_mode)) {
+		if (eff_uid == real_uid || st.st_uid == real_uid) {
+			Panic(0, "%s is not a directory.", SocketPath);
+		} else {
+			Panic(0, "Error accessing %s", SocketPath);
+		}
+	}
 	if (multi) {
-		if (st.st_uid != multi_uid)
-			Panic(0, "%s is not the owner of %s.", multi, SocketPath);
+		if (st.st_uid != multi_uid) {
+			if (eff_uid == real_uid || st.st_uid == real_uid) {
+				Panic(0, "%s is not the owner of %s.", multi, SocketPath);
+			} else {
+				Panic(0, "Error accessing %s", SocketPath);
+			}
+		}
 	} else {
 #ifdef SOCKET_DIR	/* if SOCKETDIR is not defined, the socket is in $HOME.
 			   in that case it does not make sense to compare uids. */
-		if (st.st_uid != real_uid)
-			Panic(0, "You are not the owner of %s.", SocketPath);
+		if (st.st_uid != real_uid) {
+			if (eff_uid == real_uid) {
+				Panic(0, "You are not the owner of %s.", SocketPath);
+			} else {
+				Panic(0, "Error accessing %s", SocketPath);
+			}
+		}
 #endif
 	}
-	if ((st.st_mode & 0777) != 0700)
-		Panic(0, "Directory %s must have mode 700.", SocketPath);
+	if ((st.st_mode & 0777) != 0700) {
+		if (eff_uid == real_uid || st.st_uid == real_uid) {
+			Panic(0, "Directory %s must have mode 700.", SocketPath);
+		} else {
+			Panic(0, "Error accessing %s", SocketPath);
+		}
+	}
 	if (SocketMatch && strchr(SocketMatch, '/'))
 		Panic(0, "Bad session name '%s'", SocketMatch);
 	SocketName = SocketPath + strlen(SocketPath) + 1;
@@ -886,8 +927,13 @@ int main(int argc, char **argv)
 			else
 				exit(9 + (fo || oth ? 1 : 0) + fo);
 		}
-		if (fo == 0)
-			Panic(0, "No Sockets found in %s.\n", SocketPath);
+		if (fo == 0) {
+			if (eff_uid == real_uid || st.st_uid == real_uid) {
+				Panic(0, "No Sockets found in %s.\n", SocketPath);
+			} else {
+				Panic(0, "Error accessing %s", SocketPath);
+			}
+		}
 		Msg(0, "%d Socket%s in %s.", fo, fo > 1 ? "s" : "", SocketPath);
 		eexit(0);
 	}
@@ -1551,15 +1597,6 @@ void Panic(int err, const char *fmt, ...
 			if (D_userpid)
 				Kill(D_userpid, SIG_BYE);
 		}
-	if (tty_oldmode >= 0) {
-#if defined(HAVE_SETEUID)
-		if (setuid(own_uid))
-			xseteuid(own_uid);	/* may be a loop. sigh. */
-#else
-		setuid(own_uid);
-#endif
-		chmod(attach_tty, tty_oldmode);
-	}
 	eexit(1);
 }
 
