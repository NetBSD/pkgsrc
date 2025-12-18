$NetBSD: patch-pam.c,v 1.1 2025/12/18 19:46:12 vins Exp $

pam: always print pam_conv messages to stderr.
See https://github.com/Duncaen/OpenDoas/issues/95

--- pam.c.orig	2025-12-18 20:38:18.189493362 +0000
+++ pam.c
@@ -104,8 +104,7 @@ pamconv(int nmsgs, const struct pam_mess
 
 		case PAM_ERROR_MSG:
 		case PAM_TEXT_INFO:
-			if (fprintf(style == PAM_ERROR_MSG ? stderr : stdout,
-			    "%s\n", msgs[i]->msg) < 0)
+		if (fprintf(stderr, "%s\n", msgs[i]->msg) < 0)
 				goto fail;
 			break;
 
