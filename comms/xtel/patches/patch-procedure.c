$NetBSD: patch-procedure.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- procedure.c.orig	2012-01-26 22:15:20.413787876 +0100
+++ procedure.c	2012-01-26 22:16:24.356173831 +0100
@@ -241,7 +241,7 @@ int fd;
 		  fclose (fp);
 		}
 		else
-		  fprintf (stderr, "run_procedure: %s: %s\n", (current_pd->p).filename, sys_errlist[errno]);
+		  fprintf (stderr, "run_procedure: %s: %s\n", (current_pd->p).filename, strerror(errno));
 	      }
 	    break;
 
@@ -255,7 +255,7 @@ int fd;
 		  fclose (fp);
 		}
 		else
-		  fprintf (stderr, "run_procedure: %s: %s\n", (current_pd->p).filename, sys_errlist[errno]);
+		  fprintf (stderr, "run_procedure: %s: %s\n", (current_pd->p).filename, strerror(errno));
 	      }
 
 	    break;
