$NetBSD: patch-password.c,v 1.1 2017/08/16 15:18:24 jperkin Exp $

Avoid "Missing sentinel in function call" warnings.

--- password.c.orig	2017-06-28 12:50:49.000000000 +0000
+++ password.c
@@ -73,7 +73,7 @@ static char *password_prompt_askpass(con
 		close(read_fds[1]);
 		close(write_fds[0]);
 		close(write_fds[1]);
-		execlp(askpass, "lpass-askpass", prompt, NULL);
+		execlp(askpass, "lpass-askpass", prompt, (char *)0);
 		_exit(76);
 	}
 	close(read_fds[1]);
@@ -266,7 +266,7 @@ char *password_prompt(const char *prompt
 		close(read_fds[1]);
 		close(write_fds[0]);
 		close(write_fds[1]);
-		execlp("pinentry", "pinentry", NULL);
+		execlp("pinentry", "pinentry", (char *)0);
 		_exit(76);
 	}
 	close(read_fds[1]);
