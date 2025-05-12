$NetBSD: patch-attacher.c,v 1.1 2025/05/12 16:03:20 wiz Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- attacher.c.orig	2024-08-28 19:55:03.000000000 +0000
+++ attacher.c
@@ -127,9 +127,6 @@ int Attach(int how)
 		xseteuid(multi_uid);
 		xseteuid(own_uid);
 #endif
-		if (chmod(attach_tty, 0666))
-			Panic(errno, "chmod %s", attach_tty);
-		tty_oldmode = tty_mode;
 	}
 
 	memset((char *)&m, 0, sizeof(Message));
@@ -279,12 +276,6 @@ int Attach(int how)
 			pause();	/* wait for SIGCONT */
 		xsignal(SIGCONT, SIG_DFL);
 		ContinuePlease = false;
-		xseteuid(own_uid);
-		if (tty_oldmode >= 0)
-			if (chmod(attach_tty, tty_oldmode))
-				Panic(errno, "chmod %s", attach_tty);
-		tty_oldmode = -1;
-		xseteuid(real_uid);
 	}
 	rflag = 0;
 	return 1;
@@ -334,11 +325,6 @@ void AttacherFinit(int sigsig)
 			close(s);
 		}
 	}
-	if (tty_oldmode >= 0) {
-		if (setuid(own_uid))
-			Panic(errno, "setuid");
-		chmod(attach_tty, tty_oldmode);
-	}
 	exit(0);
 }
 
@@ -457,13 +443,16 @@ void SendCmdMessage(char *sty, char *mat
 	}
 	p = m.m.command.cmd;
 	n = 0;
+	size_t space_left = ARRAY_SIZE(m.m.command.cmd);
+
 	for (; *av && n < MAXARGS - 1; ++av, ++n) {
-		size_t len;
-		len = strlen(*av) + 1;
-		if (p + len >= m.m.command.cmd + ARRAY_SIZE(m.m.command.cmd) - 1)
-			break;
-		strncpy(p, *av, MAXPATHLEN);
-		p += len;
+		int printed = snprintf(p, space_left, "%s", *av);
+		if (printed < 0 || (size_t)printed >= space_left)
+			Panic(0, "Total length of the command to send too large.\n");
+
+		printed += 1; // add null terminator
+		p += printed;
+		space_left -= printed;
 	}
 	*p = 0;
 	m.m.command.nargs = n;
