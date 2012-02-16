$NetBSD: patch-cf_sunos4.h,v 1.1 2012/02/16 17:32:45 hans Exp $

--- cf/sunos4.h.orig	1997-02-22 00:06:27.000000000 +0100
+++ cf/sunos4.h	2012-01-26 18:21:36.676350683 +0100
@@ -70,7 +70,6 @@
 #define _PATH_UTMP      "/etc/utmp"
 #define _PATH_WTMP      "/var/adm/wtmp"
 #define _PATH_LASTLOG   "/var/adm/lastlog"
-#define _PATH_MPOOL_PID	"/etc/mpoold.pid"
 
 #define UT_NAMESIZE     8
 #define UT_LINESIZE     8
@@ -115,6 +114,28 @@
 		  (warn ("%d baud not supported: using 38400", speed),	\
 		   B38400))))))))))))))))
 
+#define NORMAL_TTY(ts)					\
+  ((ts.c_iflag |= ICRNL | IMAXBEL | BRKINT),		\
+   (ts.c_oflag |= OPOST | ONLCR),			\
+   (ts.c_cflag = (ts.c_cflag & ~CLOCAL) | HUPCL),	\
+   (ts.c_lflag |= (ICANON | ISIG | IEXTEN | ECHO | 	\
+		    ECHOE | ECHOKE | ECHOCTL | PENDIN)),\
+   (ts.c_cc [VEOF] = 4),	/* Control D */		\
+   (ts.c_cc [VEOL] = _POSIX_VDISABLE),			\
+   (ts.c_cc [VEOL2] = _POSIX_VDISABLE),			\
+   (ts.c_cc [VERASE] = 127),	/* Delete */		\
+   (ts.c_cc [VWERASE] = 23),	/* Control W */		\
+   (ts.c_cc [VKILL] = 21),	/* Control U */		\
+   (ts.c_cc [VREPRINT] = 18),	/* Control R */		\
+   (ts.c_cc [VINTR] = 3),	/* Control C */		\
+   (ts.c_cc [VQUIT] = 28),	/* Control \ */		\
+   (ts.c_cc [VSUSP] = 26),	/* Control Z */		\
+   (ts.c_cc [VDSUSP] = 6),	/* Control F */		\
+   (ts.c_cc [VSTART] = 17),	/* Control Q */		\
+   (ts.c_cc [VSTOP] = 19),	/* Control S */		\
+   (ts.c_cc [VLNEXT] = 22),	/* Control V */		\
+   (ts.c_cc [VDISCARD] = _POSIX_VDISABLE))
+
 #define SET_TX_SPEED(ts, speed)						\
   (ts.c_cflag = (ts.c_cflag & ~CBAUD) |					\
    CVT_BAUD (speed))
@@ -133,8 +154,9 @@
 #define	_PATH_TTYLOCK	"/var/spool/locks/LCK..%s"
 
 /* Varargs stuff... */
-#include <varargs.h>
-#define VA_DOTDOTDOT va_alist
-#define VA_start(list, last) va_start (list)
+#include <stdarg.h>
+#define VA_DOTDOTDOT ...
+#define va_dcl
+#define VA_start(list, last) va_start (list, last)
 
-#define vsnprintf(buf, size, fmt, list) vsprintf (buf, fmt, list)
+#define _PATH_MPOOL_PID	"/var/run/mpoold.pid"
