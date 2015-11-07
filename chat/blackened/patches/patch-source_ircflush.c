$NetBSD: patch-source_ircflush.c,v 1.1 2015/11/07 21:16:36 dholland Exp $

Remove bogus includes.

--- source/ircflush.c~	1999-07-16 21:21:43.000000000 +0000
+++ source/ircflush.c
@@ -12,15 +12,6 @@ static	char	rcsid[] = "@(#)$Id: ircflush
 #include "irc.h"
 #include <sys/wait.h>
 
-#ifndef __linux__
-# ifdef __svr4__
-#  include <sys/termios.h>
-# else
-#  include <sgtty.h>	/* SVR4 => sgtty = yuk */
-# endif /* SOLARIS */
-#endif /* __linux__ */
-
-
 #define BUFFER_SIZE 1024
 
 /* descriptors of the tty and pty */
