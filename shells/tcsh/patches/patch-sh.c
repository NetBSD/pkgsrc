$NetBSD: patch-sh.c,v 1.1 2012/10/10 19:19:58 dholland Exp $

Avoid calling tcsetpgrp on fd -1; prevents libc diagnostic assertion
in NetBSD. From christos.

--- sh.c~	2011-11-29 18:38:54.000000000 +0000
+++ sh.c
@@ -1215,14 +1215,14 @@ main(int argc, char **argv)
 
 #ifdef NeXT
 	    /* NeXT 2.0 /usr/etc/rlogind, does not set our process group! */
-	    if (shpgrp == 0) {
+	    if (f != -1 && shpgrp == 0) {
 	        shpgrp = getpid();
 		(void) setpgid(0, shpgrp);
 	        (void) tcsetpgrp(f, shpgrp);
 	    }
 #endif /* NeXT */
 #ifdef BSDJOBS			/* if we have tty job control */
-	    if (grabpgrp(f, shpgrp) != -1) {
+	    if (f != -1 && grabpgrp(f, shpgrp) != -1) {
 		/*
 		 * Thanks to Matt Day for the POSIX references, and to
 		 * Paul Close for the SGI clarification.
