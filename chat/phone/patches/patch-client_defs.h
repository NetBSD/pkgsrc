$NetBSD: patch-client_defs.h,v 1.1 2014/09/11 07:15:56 dholland Exp $

- Don't rely on __unused from netbsd's <cdefs.h> existing.
- Use a more portable username size symbol for the sake of Solaris.

--- client/defs.h~	2013-01-02 23:00:42.000000000 +0000
+++ client/defs.h
@@ -25,6 +25,10 @@
 #include <curses.h>
 #include <netdb.h>
 
+#ifndef __unused
+#define __unused __attribute__((__unused__))
+#endif
+
 int	msgpending;
 int	killedchild;
 int	changed_size;
@@ -38,7 +38,7 @@ char	*mytty;			    /* tty he's on	      
 char	*home;			    /* home directory	       */
 const char *shell;		    /* preferred shell	       */
 char	myhost[MAXHOSTNAMELEN];	    /* local host name	       */
-char	realname[MAXLOGNAME];	    /* from password file      */
+char	realname[LOGIN_NAME_MAX];   /* from password file      */
 int	maxx;			    /* max legal x coordinate  */
 int	maxy;			    /* max legal y coordinate  */
 int	stream;			    /* stream socket filedes   */
