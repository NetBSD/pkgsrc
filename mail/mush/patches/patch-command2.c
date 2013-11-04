$NetBSD: patch-command2.c,v 1.1 2013/11/04 15:34:38 christos Exp $

- avoid pointer<->integer conversions

--- command2.c	2013-11-04 10:20:21.000000000 -0500
+++ command2.c	2013-11-04 10:28:08.000000000 -0500
@@ -310,7 +310,7 @@
 	    execute(edit_cmd);
 	    turnoff(glob_flags, IS_GETTING);
 	    free_vec(edit_cmd);
-	    if (load_folder(b, FALSE, (char *)i) > 0) {
+	    if (load_folder(b, FALSE, (char *)&i) > 0) {
 		(void) unlink(b);
 		edited = 1;
 	    }
