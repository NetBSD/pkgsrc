$NetBSD: patch-openpty.c,v 1.1 2025/05/23 09:28:50 jperkin Exp $

Implement openpty() for illumos.  Based on jclulow's patches for neovim.

--- openpty.c.orig	2025-05-23 08:50:01.278615842 +0000
+++ openpty.c
@@ -0,0 +1,175 @@
+#include <sys/types.h>
+#include <sys/termios.h>
+#include <stdlib.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <stropts.h>
+#include <strings.h>
+#include <errno.h>
+
+static int
+openpty_failure(int c, int s, int e)
+{
+	if (s >= 0) {
+		(void) close(s);
+	}
+
+	if (c >= 0) {
+		(void) close(c);
+	}
+
+	errno = e;
+	return (-1);
+}
+
+int
+openpty(int *controlp, int *subordp, char *name, const struct termios *termp,
+    const struct winsize *winp)
+{
+	int c = -1;
+	int s = -1;
+	char *sname;
+	int found;
+
+	/*
+	 * Open a pseudo-terminal control device, making sure not to set it as
+	 * the controlling terminal for this process:
+	 */
+	if ((c = posix_openpt(O_RDWR | O_NOCTTY)) < 0) {
+		return (-1);
+	}
+
+	/*
+	 * Set permissions and ownership on the subordinate device and unlock
+	 * it:
+	 */
+	if (grantpt(c) < 0 || unlockpt(c) < 0) {
+		return (openpty_failure(c, s, errno));
+	}
+
+	/*
+	 * Open the subordinate device for this control device, again without
+	 * setting it as the controlling terminal for this process:
+	 */
+	if ((sname = ptsname(c)) == NULL ||
+	    (s = open(sname, O_RDWR | O_NOCTTY)) < 0) {
+		return (openpty_failure(c, s, errno));
+	}
+
+	/*
+	 * Check to see if the STREAMS modules have been automatically pushed:
+	 */
+	if ((found = ioctl(s, I_FIND, "ldterm")) < 0) {
+		return (openpty_failure(c, s, errno));
+	} else if (found == 0) {
+		/*
+		 * The line discipline is not present, so push the appropriate
+		 * STREAMS modules for the subordinate device:
+		 */
+		if (ioctl(s, __I_PUSH_NOCTTY, "ptem") < 0 ||
+		    ioctl(s, __I_PUSH_NOCTTY, "ldterm") < 0) {
+			return (openpty_failure(c, s, errno));
+		}
+	}
+
+	/*
+	 * If provided, set the terminal parameters:
+	 */
+	if (termp != NULL && tcsetattr(s, TCSAFLUSH, termp) != 0) {
+		return (openpty_failure(c, s, errno));
+	}
+
+	/*
+	 * If provided, set the window size:
+	 */
+	if (winp != NULL && ioctl(s, TIOCSWINSZ, winp) != 0) {
+		return (openpty_failure(c, s, errno));
+	}
+
+	/*
+	 * If the caller wants the name of the subordinate device, copy it out.
+	 *
+	 * Note that this is a terrible interface: there appears to be no
+	 * standard upper bound on the copy length for this pointer.  Nobody
+	 * should pass anything but NULL here, preferring instead to use
+	 * ptsname(3C) directly.
+	 */
+	if (name != NULL) {
+		strcpy(name, sname);
+	}
+	*controlp = c;
+	*subordp = s;
+	return (0);
+}
+
+int
+login_tty(int t)
+{
+	/*
+	 * Use TIOCSCTTY to set this terminal device as our controlling
+	 * terminal.  This will fail (with ENOTTY) if we are not the leader in
+	 * our own session, so we call setsid() first.  Finally, arrange for
+	 * the pseudo-terminal to occupy the standard I/O descriptors.
+	 */
+	if (setsid() < 0 ||
+	    ioctl(t, TIOCSCTTY, 0) < 0 ||
+	    dup2(t, STDIN_FILENO) < 0 ||
+	    dup2(t, STDOUT_FILENO) < 0 ||
+	    dup2(t, STDERR_FILENO) < 0) {
+		return (-1);
+	}
+
+	/*
+	 * Close the inherited descriptor, taking care to avoid closing the
+	 * standard descriptors by mistake:
+	 */
+	if (t > STDERR_FILENO) {
+		(void) close(t);
+	}
+
+	return (0);
+}
+
+int
+forkpty(int *controlp, char *name, const struct termios *termp,
+    const struct winsize *winp)
+{
+	int s;
+	int c;
+	int pid;
+	if (openpty(&c, &s, name, termp, winp) != 0) {
+		return (-1);
+	}
+	if ((pid = fork()) < 0) {
+		return (openpty_failure(c, s, errno));
+	} else if (pid > 0) {
+		/*
+		 * In the parent process, we close the subordinate device and
+		 * return the process ID of the new child:
+		 */
+		(void) close(s);
+		*controlp = c;
+		return (pid);
+	}
+
+	/*
+	 * The rest of this function executes in the child process.
+	 */
+
+	/*
+	 * Close the control side of the pseudo-terminal pair:
+	 */
+	(void) close(c);
+
+	if (login_tty(s) != 0) {
+		/*
+		 * At this stage there are no particularly good ways to handle
+		 * failure.  Exit as abruptly as possible, using _exit() to
+		 * avoid messing with any state still shared with the parent
+		 * process.
+		 */
+		_exit(EXIT_FAILURE);
+	}
+
+	return (0);
+}
