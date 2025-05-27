$NetBSD: patch-ui.c,v 1.2 2025/05/27 19:15:12 vins Exp $

* stdarg.h required for va_* macros.
* strncpy() should not depend on the size of the source argument.

--- ui.c.orig	2024-08-13 10:49:48.000000000 +0000
+++ ui.c
@@ -12,6 +12,7 @@
 #include <sys/utsname.h>
 #include <pwd.h>
 #include <signal.h>
+#include <stdarg.h>
 #include <unistd.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -1152,7 +1153,7 @@ int edit_regexp(void)
 		/* display them lines */
 		for(loop=0; loop<cur -> n_re; loop++)
 		{
-			strncpy(buffer, (cur -> pre)[loop].regex_str, 34);
+			memcpy(buffer, (cur -> pre)[loop].regex_str, 34);
 			if (loop == cur_re)
 				ui_inverse_on(mywin);
 			mvwprintw(mywin -> win, 4 + loop, 1, "%c%c %s", 
@@ -1162,7 +1163,7 @@ int edit_regexp(void)
 			if (toupper((cur -> pre)[loop].use_regex) == 'X')
 			{
 				char dummy[18];
-				strncpy(dummy, (cur -> pre)[loop].cmd, min(17, strlen((cur -> pre)[loop].cmd)));
+				memcpy(dummy, (cur -> pre)[loop].cmd, min(17, strlen((cur -> pre)[loop].cmd)));
 				dummy[17]=0x00;
 				mvwprintw(mywin -> win, 4 + loop, 42, "%s", dummy);
 				wmove(mywin -> win, 4 + loop, 41);
