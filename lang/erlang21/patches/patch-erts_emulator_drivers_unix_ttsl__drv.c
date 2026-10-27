$NetBSD: patch-erts_emulator_drivers_unix_ttsl__drv.c,v 1.1 2026/10/27 20:38:04 wiz Exp $

Avoid using a keyword (in some C/C++ standards) as label name.

--- erts/emulator/drivers/unix/ttsl_drv.c.orig	2026-10-27 20:35:16.647493992 +0000
+++ erts/emulator/drivers/unix/ttsl_drv.c
@@ -1325,17 +1325,17 @@ static int start_termcap(void)
 
     capbuf = driver_alloc(1024);
     if (!capbuf)
-	goto false;
+	goto st_false;
     eres = erl_drv_getenv("TERM", capbuf, &envsz);
     if (eres == 0)
 	env = capbuf;
     else if (eres < 0) {
         DEBUGLOG(("start_termcap: failure in erl_drv_getenv(\"TERM\", ..) = %d\n", eres));
-	goto false;
+	goto st_false;
     } else /* if (eres > 1) */ {
       char *envbuf = driver_alloc(envsz);
       if (!envbuf)
-	  goto false;
+	  goto st_false;
       while (1) {
 	  char *newenvbuf;
 	  eres = erl_drv_getenv("TERM", envbuf, &envsz);
@@ -1345,7 +1345,7 @@ static int start_termcap(void)
           if (eres < 0 || !newenvbuf) {
               DEBUGLOG(("start_termcap: failure in erl_drv_getenv(\"TERM\", ..) = %d or realloc buf == %p\n", eres, newenvbuf));
 	      env = newenvbuf ? newenvbuf : envbuf;
-	      goto false;
+	      goto st_false;
 	  }
 	  envbuf = newenvbuf;
       }
@@ -1353,7 +1353,7 @@ static int start_termcap(void)
     }
     if ((tres = tgetent((char*)lbuf, env)) <= 0) {
         DEBUGLOG(("start_termcap: failure in tgetent(..) = %d\n", tres));
-        goto false;
+        goto st_false;
     }
     if (env != capbuf) {
 	env = NULL;
@@ -1375,7 +1375,7 @@ static int start_termcap(void)
         return TRUE;
     }
     DEBUGLOG(("start_termcap: failed start\n"));
- false:
+ st_false:
     if (env && env != capbuf)
 	driver_free(env);
     if (capbuf)
