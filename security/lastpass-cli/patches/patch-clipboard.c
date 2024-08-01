$NetBSD: patch-clipboard.c,v 1.2 2024/08/01 20:10:15 vins Exp $

Avoid "Missing sentinel in function call" warnings.

--- clipboard.c.orig	2024-05-16 16:29:10.000000000 +0000
+++ clipboard.c
@@ -64,7 +64,7 @@ void exec_command(char *command) {
 		shell = "/bin/sh";
 	}
 
-	execlp(shell, shell, "-c", command, NULL);
+	execlp(shell, shell, "-c", command, (char *)0);
 }
 
 void clipboard_open(void)
@@ -91,11 +91,11 @@ void clipboard_open(void)
 			exec_command(clipboard_command);
 			die("Unable to copy contents to clipboard. Please make sure you have `wl-clip`, `xclip`, `xsel`, `pbcopy`, or `putclip` installed.");
 		} else {
-			execlp("wl-copy", "wl-copy", NULL);
-			execlp("xclip", "xclip", "-selection", "clipboard", "-in", NULL);
-			execlp("xsel", "xsel", "--clipboard", "--input", NULL);
-			execlp("pbcopy", "pbcopy", NULL);
-			execlp("putclip", "putclip", "--dos", NULL);
+			execlp("wl-copy", "wl-copy", (char *)0);
+			execlp("xclip", "xclip", "-selection", "clipboard", "-in", (char*)0);
+			execlp("xsel", "xsel", "--clipboard", "--input", (char *)0);
+			execlp("pbcopy", "pbcopy", (char *)0);
+			execlp("putclip", "putclip", "--dos", (char *)0);
 			die("Unable to copy contents to clipboard. Please make sure you have `xclip`, `xsel`, `pbcopy`, or `putclip` installed.");
 		}
 	}
